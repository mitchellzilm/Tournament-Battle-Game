#include "lightweapon.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

lightweapon::lightweapon(){
	namewep="null";
	dmgwep=0;
	countwep=0;
}

lightweapon::lightweapon(string wepname, int wepdamage, int wepcount){
	namewep=wepname;
	dmgwep=wepdamage;
	countwep=wepcount;
}

int lightweapon::attack(){ //week11 Tues virtual func deals 22 - 28 dmg
	int val = 0;
	val =  dmgwep + (rand() % 6);
	return val;
};


lightweapon::~lightweapon(){}