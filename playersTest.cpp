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
extern int read_strength_input();
extern int read_speed_input(int strength_input);
extern int read_drip_input(int strength_input, int speed_input);
int main(){
    players p8;
    p8.playerfunction();
}