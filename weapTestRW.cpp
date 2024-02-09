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
	rangeweapon* rw1 = new rangeweapon("Bow", 3, 1);
	rangeweapon* rw4 = new rangeweapon("Bow", 22, 1);

	cout<<rw1->get_name()<<endl;
	cout<<rw1->get_damage()<<endl;
	cout<<rw1->get_wepcount()<<endl;
	
	cout<<rw4->get_name()<<endl;
	cout<<rw4->get_damage()<<endl;
	cout<<rw4->get_wepcount()<<endl;
}
	
	
