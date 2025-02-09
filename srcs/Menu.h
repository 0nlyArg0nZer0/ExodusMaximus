#pragma once
#include "includes.h"





// Created with ReClass.NET 1.2 by KN4CK3R

class namePadding
{
public:
	char preNamePadding[517];     //0x0000
	char maxCharacters[16];     //0x0205
	char postNamePadding[3641];    //0x0215

	//offset 0x205



}; //Size: 0x104E





namespace Menu
{


	inline void MainMenu(Memory& memory, std::uintptr_t baseAddress)
	{
		std::uintptr_t localPlayerAddress = memory.Read<std::uintptr_t>(baseAddress + Offsets::localPlayer);
	    std::uintptr_t nameAddress = localPlayerAddress + Offsets::namePadding;


		std::string inGameName = memory.Read<namePadding>(nameAddress).preNamePadding;






		std::cout << Color::cyan << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n" << Color::reset;
		
		std::cout << Color::magenta << "\t\t0nlyArg0ns2 First  External Ex0Byte" << Color::reset << "\n\n" << std::endl;



		std::cout << Color::yellow << "\t\t\t\tC++" << Color::reset << "\n\n" << std::endl;


		std::cout << Color::bright_green << "\t\tThis code is intended for educational use only, showcasing techniques and concepts I have learned." << Color::reset << "\n\n\n" << std::endl;


		std::cout << Color::cyan << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n" << Color::reset;










		std::cout << "[F1]  Cheat Menu\n\n";

		std::cout << "[F2]  Settings Menu \t Comming Soon\n\n";

		std::cout << "[F3]  Info\n\n";

		std::cout << "[ENTF]  EXIT\n\n";

		std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";



	}



	inline void CheatsMenu()
	{
		std::cout << Color::cyan << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n" << Color::reset;
		std::cout <<Color::red <<  " \t    Cheat Menu \n\n" << Color::reset;



		std::cout << "[F1] Main Menu \n\n\n";


		std::cout << Color::cyan << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n" << Color::reset;

		std::cout << "[F5] God Mode\n\n";

		std::cout << "[F6] Armor Hack\n\n";

		std::cout << "[F7] Infinite Ammo\n\n";

		std::cout << "[F9] Show LocalPlayer Cordinates(Buggy)\n\n";

		std::cout << "[F10] Show Entity Cordinates (Buggy)\n\n\n";

		
		std::cout << Color::green <<"More Comming Soon....\n\n\n\n" << Color::reset <<std::endl;
		


		std::cout << Color::cyan << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
	}


	inline void SettingMenu()
	{
		std::cout << Color::cyan << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n" << Color::reset;
		std::cout << Color::green << " \t   Settings Menu \n\n" << Color::reset;



		std::cout << "[F1] Main Menu \n\n\n";


		std::cout << Color::cyan << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n" << Color::reset;

	}

}