#include <iostream>
#include <string>
#include "players.h"
#include "weapons.h"
#include "heavyweapon.h"
#include "lightweapon.h"
#include "rangeweapon.h"
using namespace std;
int main(){

// creating the light weapon objects
	lightweapon* lw1 = new lightweapon("Dagger", 3, 1);
	lightweapon* lw4 = new lightweapon("Hatchet", 22, 1);

	cout<<lw1->get_name()<<endl;
	cout<<lw1->get_damage()<<endl;
	cout<<lw1->get_wepcount()<<endl;
	
	cout<<lw4->get_name()<<endl;
	cout<<lw4->get_damage()<<endl;
	cout<<lw4->get_wepcount()<<endl;
}
	
	
