#pragma once

#include "includes.h"








namespace Cheats
{





    void ShowCoordinates(Memory& memory, std::uintptr_t baseAddress);

    void ShowEntityCoordinates(Memory& memory, std::uintptr_t baseAddress);

    void ToggleGodMode(Memory& memory, std::uintptr_t localPlayerAddress, bool& isActive);

    void ToggleAmmoHack(Memory& memory, std::uintptr_t localPlayerAddress, bool& isActive);

    
	
    



}
