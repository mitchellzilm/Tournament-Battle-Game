#ifndef LIGHTWEAPON_H
#define LIGHTWEAPON_H
#include "weapons.h"
#include <string>
using namespace std;


class lightweapon : public weapons
{
public:
	lightweapon();
	lightweapon(string wepname, int damage, int wepcount);
	string *lightweapon_action();
	int attack();
	~lightweapon();


private:
};

#endif