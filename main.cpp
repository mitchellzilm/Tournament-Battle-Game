#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "players.h"
#include "weapons.h"
#include "heavyweapon.h"
#include "lightweapon.h"
#include "rangeweapon.h"
#include "Armour.h"
using namespace std;
extern int weapon_function();
extern int armourChoice();
extern int choice();
extern void battle_function(string userName, int userStrength, int userSpeed, int userDrip, int wepChoice, int armChoice);

int main(){
	//creates 8 player objects 1 of which will be the player of the game
	players p1, p2, p3, p8;
	p1 = players("Cila Malitz", 5, 2, 8);
	p2 = players("Tachel Rang", 1, 8, 6);
	p3 = players("Yuddlie Du", 11, 1, 3);
	p8.playerfunction();
	string userName=p8.getName();
	int userStrength = p8.getStrength();
	int userSpeed = p8.getSpeed();
	int userDrip = p8.getDrip();

    Armour playerarmour;                                                                 //initialise player gear. i will try to define this as whatever the player chooses
    weapons* playerweapon;

    cout << "Your strength is: " << p8.getStrength() << endl;
    cout << "Your speed is: " << p8.getSpeed() << endl;
    cout << "Your drip is: "<< p8.getDrip() << endl;
    cout << endl;

    heavyweapon* hw1 = new heavyweapon("Sword", 20, 2);
    heavyweapon* hw2 = new heavyweapon("Battleaxe", 20, 2);
    heavyweapon* hw3 = new heavyweapon("Sickle", 20, 2);
    lightweapon* lw1 = new lightweapon("Dagger", 22, 1);
    lightweapon* lw2 = new lightweapon("Hatchet", 22, 1);
    lightweapon* lw3 = new lightweapon("Machete", 22, 1);
    rangeweapon* rw1 = new rangeweapon("Bow", 10, 1);
    rangeweapon* rw2 = new rangeweapon("Spear", 10, 1);

    weapons**over_array_wep=new weapons*[8];
    over_array_wep[0]=hw1;
    over_array_wep[1]=hw2;
    over_array_wep[2]=hw3;
    over_array_wep[3]=lw1;
    over_array_wep[4]=lw2;
    over_array_wep[5]=lw3;
    over_array_wep[6]=rw1;
    over_array_wep[7]=rw2;


	int m = weapon_function();
	playerweapon = over_array_wep[m];
	int wepChoice = m;

	Armour a[6]={
		Armour(3, 1, "Leather"),
		Armour(4, 1, "Gold"),
		Armour(5, 1, "Chain"),
		Armour(6, 2, "Diamond"),
		Armour(7, 2, "Iron"),
		Armour(8, 2, "Netherite")};

	int k = armourChoice();
	playerarmour = a[k-1];
	int armChoice = k;

    battle_function(p8.getName(), p8.getStrength(), p8.getSpeed(), p8.getDrip(), m, k);
}

