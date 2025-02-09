#include "Hacks.h"



static void ClearMessageAfterDelay(int milliseconds)
{
    std::thread([milliseconds]()
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds)); // Warten

            
            for (int i = 0; i < 2; ++i)
            {
                std::cout << "\033[A" << "\r                                                                    \r" << std::flush; // Eine Zeile nach oben und löschen
            }
        }).detach();
}


void Cheats::ShowCoordinates(Memory& memory, std::uintptr_t baseAddress)
{
    std::uintptr_t localPlayerAddress = memory.Read<std::uintptr_t>(baseAddress + Offsets::localPlayer);

    if (!localPlayerAddress)
    {
        std::cerr << "Fehler: Local Player Address nicht gefunden!" << std::endl;
        return;
    }

    std::uintptr_t xAddress = localPlayerAddress + Offsets::positionX;
    std::uintptr_t yAddress = localPlayerAddress + Offsets::positionY;
    std::uintptr_t zAddress = localPlayerAddress + Offsets::positionZ;

    while (true)
    {
        float x = memory.Read<float>(xAddress);
        float y = memory.Read<float>(yAddress);
        float z = memory.Read<float>(zAddress);

        // Use '\r' to overwrite the same line in the console, and clear it before printing new data
        std::cout << "\r"
            << "X: " << std::setw(6) << std::fixed << std::setprecision(2) << x
            << " | Y: " << std::setw(6) << std::fixed << std::setprecision(2) << y
            << " | Z: " << std::setw(6) << std::fixed << std::setprecision(2) << z
            << std::flush; // Flush output to make it appear immediately

        // Optional: Reduce sleep time to make it feel smoother (e.g., every 100 ms instead of 300 ms)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }


     


}

void Cheats::ShowEntityCoordinates(Memory& memory, std::uintptr_t baseAddress)
{
    // Get the base address of the entity list
    std::uintptr_t entityListBase = memory.Read<std::uintptr_t>(baseAddress + Offsets::entityList);
    size_t maxEntities = 4; // Maximum number of entities to read (4 entities)


    // Save the initial cursor position
    std::cout << "\033[s"; // Save cursor position

    // Loop to continuously update the coordinates
    while (true)
    {


        // Restore the initial cursor position
        std::cout << "\033[u"; // Restore cursor position




        for (size_t i = 1; i < maxEntities; ++i) {
            // Move the cursor to the correct line (1 + i because of the header)



            std::cout << "\033[" << i + 1 << "B"; // Move cursor down by i+1 rows (header + i)




            // Get the address of the current entity
            std::uintptr_t entityAddress = memory.Read<std::uintptr_t>(entityListBase + i * sizeof(std::uintptr_t));




            if (entityAddress != 0) {
                // Read entity position (X, Y, Z)
                float x = memory.Read<float>(entityAddress + Offsets::positionX);
                float y = memory.Read<float>(entityAddress + Offsets::positionY);
                float z = memory.Read<float>(entityAddress + Offsets::positionZ);

                // Print the updated coordinates for the current entity
                std::cout << "Entity " << i + 0 << " -> "
                    << "X: " << std::setw(6) << std::fixed << std::setprecision(2) << x
                    << " | Y: " << std::setw(6) << std::fixed << std::setprecision(2) << y
                    << " | Z: " << std::setw(6) << std::fixed << std::setprecision(2) << z
                    << std::flush; // Flush output to make it appear immediately
            }

            // Move the cursor back up to the saved line
            std::cout << "\033[u"; // Restore cursor position
        }

        // Sleep briefly to make the updates smooth
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Adjust as necessary
    }
}

void Cheats::ToggleGodMode(Memory& memory, std::uintptr_t localPlayerAddress, bool& isActive)
{
    if (isActive)
        memory.Write<int>(localPlayerAddress + Offsets::health, 1337);
    else
        memory.Write<int>(localPlayerAddress + Offsets::health, 100);

    isActive = !isActive;
	std::cout << Color::green << "\n[GodMode] " << (isActive ? Color::green, "ENABLED ",  Color::red : "DISABLED ") << std::flush;



    
    ClearMessageAfterDelay(2000);
}

void Cheats::ToggleAmmoHack(Memory& memory, std::uintptr_t localPlayerAddress, bool& isActive)
{
    int ammoValue = isActive ? 1337 : 30;
    memory.Write<int>(localPlayerAddress + Offsets::assaultRifleAmmo, ammoValue);
    memory.Write<int>(localPlayerAddress + Offsets::submachineGunAmmo, ammoValue);
    memory.Write<int>(localPlayerAddress + Offsets::shotgunAmmo, 7);
    memory.Write<int>(localPlayerAddress + Offsets::sniperAmmo, 5);
    memory.Write<int>(localPlayerAddress + Offsets::pistolAmmo, 10);
    memory.Write<int>(localPlayerAddress + Offsets::grenadeAmmo, isActive ? 1337 : 0);

    isActive = !isActive;
    std::cout << "\n[AmmoHack] " << (isActive ? "AKTIVIERT" : "DEAKTIVIERT") << std::flush;

    // Nach 3 Sekunden löschen
    ClearMessageAfterDelay(3000);
}


