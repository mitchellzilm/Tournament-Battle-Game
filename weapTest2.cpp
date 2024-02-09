#include <iostream>
#include <string>
#include <cstdlib>
#include "players.h"
#include "weapons.h"
#include "heavyweapon.h"
#include "lightweapon.h"
#include "rangeweapon.h"

using namespace std;
int main(){

    heavyweapon* hw1 = new heavyweapon("Sword", 3, 2);

    lightweapon* lw1 = new lightweapon("Dagger", 3, 1);                      //making sure virtual function works - the basics work ytb, we will use "xw1 -> attack()" in the battle loop

    rangeweapon* rw1 = new rangeweapon("Bow", 3, 1);

    cout << hw1 -> attack() << endl;
    cout << hw1 -> attack() << endl;
    cout << hw1 -> attack() << endl;
    cout << hw1 -> attack() << endl;
    cout << lw1 -> attack() << endl;
    cout << lw1 -> attack() << endl;
    cout << lw1 -> attack() << endl;
    cout << rw1 -> attack() << endl;
    cout << rw1 -> attack() << endl;
    cout << rw1 -> attack() << endl;

}