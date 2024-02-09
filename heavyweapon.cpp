#include "heavyweapon.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

heavyweapon::heavyweapon(){
	namewep="null";
	dmgwep=0;
	countwep=0;
}

heavyweapon::heavyweapon(string wepname, int wepdamage, int wepcount){
	namewep=wepname;
	dmgwep=wepdamage;
	countwep=wepcount;
}

int heavyweapon::attack(){//week11 Tues virtual func deals 20 to 30 dmg
	int val = 0;
	val =  dmgwep + (rand() % 10);
	return val;
};

heavyweapon::~heavyweapon(){}