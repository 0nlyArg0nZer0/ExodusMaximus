#pragma once
#include "includes.h"


class Offsets 
{
public:

	//Player 
	static constexpr auto localPlayer = 0x0017E0A8;
	static constexpr std::uintptr_t fieldOfView = 0x18A7CC;
	static constexpr std::uintptr_t health = 0xEC;
	static constexpr std::uintptr_t armor = 0xF0;
	static constexpr std::uintptr_t playerName = 0x32C;
	static constexpr std::uintptr_t event_switchGun = 0xC8938;
	static constexpr std::uintptr_t namePadding = 0x205;

	//Player Camera
	static constexpr std::uintptr_t cameraX = 0x34;
	static constexpr std::uintptr_t cameraZ = 0x38;


	//Ammo & Wepon

	static constexpr std::uintptr_t assaultRifleAmmo = 0x140;
	static constexpr std::uintptr_t submachineGunAmmo = 0x138;
	static constexpr std::uintptr_t sniperAmmo = 0x13C;
	static constexpr std::uintptr_t shotgunAmmo = 0x134;
	static constexpr std::uintptr_t pistolAmmo = 0x12C;
	static constexpr std::uintptr_t grenadeAmmo = 0x144;

	static constexpr std::uintptr_t fastFireAssaultRifle = 0x164;
	static constexpr std::uintptr_t fastFireSniper = 0x160;
	static constexpr std::uintptr_t fastFireShotgun = 0x158;

	static constexpr std::uintptr_t autoShoot = 0x204;


	//position
	static constexpr std::uintptr_t positionX = 0x2C;
	static constexpr std::uintptr_t positionY = 0x30;
	static constexpr std::uintptr_t positionZ = 0x28;
	
	//Head Position
	static constexpr std::uintptr_t positionHeadX = 0x4;
	static constexpr std::uintptr_t positionHeadY = 0xC;
	static constexpr std::uintptr_t positionHeadZ = 0x8;


	
	//Entity
	static constexpr std::uintptr_t entityList = 0x18AC04;
	static constexpr std::uintptr_t playerCount = 0x18A7CC;
	static constexpr std::uintptr_t botList = 0x191FCC;


};