#include "weapons.h"
#include <iostream>
#include <string>
using namespace std;

weapons::weapons(){
	namewep="null";
	dmgwep=0;
	countwep=0;
}

weapons::weapons(string wepname, int wepdamage, int wepcount){
	namewep=wepname;
	dmgwep=wepdamage;
	countwep=wepcount;
}

string weapons::get_name(){
	return namewep;
}

int weapons::get_damage(){
	return dmgwep;
}

int weapons::get_wepcount(){
	return countwep;
}





weapons::~weapons(){}