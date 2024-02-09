#include "rangeweapon.h"
#include <iostream>
#include <string>
using namespace std;

rangeweapon::rangeweapon(){
	namewep="null";
	dmgwep=0;
	countwep=0;
}

rangeweapon::rangeweapon(string wepname, int wepdamage, int wepcount){
	namewep=wepname;
	dmgwep=wepdamage;
	countwep=wepcount;
}

int rangeweapon::attack(){//week11 Tues virtual func  deals 10-40 dmg
	int val = 0;
	val =  dmgwep + (rand() % 30);
	return val;
};

rangeweapon::~rangeweapon(){}
