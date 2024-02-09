#include <iostream>
#include <fstream>
#include <string>
#include "players.h"
#include "weapons.h"
#include "heavyweapon.h"
#include "lightweapon.h"
#include "rangeweapon.h"
#include "Armour.h"
extern int armour_type_select();
int armourChoice(){
	
	string armourArray[6] = {"Leather","Gold","Chain","Diamond","Iron","Netherite"};
    cout << "Please choose which type of armour you would like" << endl;
	cout << "For Leather, press 1" << endl;
	cout << "For Gold, press 2" << endl;
	cout << "For Chain, press 3" << endl;
	cout << "For Diamond, press 4" << endl;
	cout << "For Iron, press 5" << endl;
	cout << "For Netherite, press 6" << endl;
	int k = armour_type_select();
	
	for (int i = 0; i < 1; i++){
			cout << "You have chosen " << armourArray[k-1];
			cout << " armour\n" << endl;
			return k;
	}
	return 0;
}