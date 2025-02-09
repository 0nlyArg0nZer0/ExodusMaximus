#include "includes.h"



int main()
{
   

    bool menuOpen = false;
    bool GodModeOn = false;
    bool InfiniteAmmoOn = false;



    Memory memory{ "ac_client.exe" };
    const auto baseAddress = memory.GetModuleAddress("ac_client.exe");
    std::uintptr_t localPlayerAddress = memory.Read<std::uintptr_t>(baseAddress + Offsets::localPlayer);
    if (baseAddress == 0)
    {
        MessageBox(NULL, "Game was not found!", "Error", MB_OK | MB_ICONERROR);
        return 0;
    }

    
    



    Menu::MainMenu(memory, baseAddress);

    while (true)
    {

        //CheatMenu
        if (GetAsyncKeyState(VK_F1) & 0x8000)
        {
            system("CLS");
			if (menuOpen)
				Menu::MainMenu(memory, baseAddress);
			else
				Menu::CheatsMenu();


            menuOpen = !menuOpen; // Zustand umschalten
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }

        if (GetAsyncKeyState(VK_F2) & 0x8000)
        {
            system("CLS");
            if(menuOpen)
				Menu::MainMenu(memory, baseAddress);
            else
				Menu::SettingMenu();

            menuOpen = !menuOpen; // Zustand umschalten
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }



        //godMode
        if (GetAsyncKeyState(VK_F5) & 0x8000)
        {
            Cheats::ToggleGodMode(memory, localPlayerAddress, GodModeOn);
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }

		//InfiniteAmmo
        if (GetAsyncKeyState(VK_F7) & 0x8000)
        {
            Cheats::ToggleAmmoHack(memory, localPlayerAddress, InfiniteAmmoOn);
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }

		//showCoordinatesLocal
        if (GetAsyncKeyState(VK_F9) & 0x8000)
        {
            std::thread(Cheats::ShowCoordinates, std::ref(memory), baseAddress).detach();
			
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }

		//showCoordinatesEntity
        if (GetAsyncKeyState(VK_F10) & 0x8000)
        {
            std::thread(Cheats::ShowEntityCoordinates, std::ref(memory), baseAddress).detach();

            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }

        //exit
        if (GetAsyncKeyState(VK_DELETE) & 0x8000)
        {
            exit(0);
        }
    }


    return 0;

}

