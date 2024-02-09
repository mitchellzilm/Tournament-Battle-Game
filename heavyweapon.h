#ifndef HEAVYWEAPON_H
#define HEAVYWEAPON_H
#include "weapons.h"
#include <string>
using namespace std;


class heavyweapon : public weapons
{
public:
	heavyweapon();
	heavyweapon(string wepname, int damage, int wepcount);
	void heavywepchoice();
	string *heavyweapon_action();
	int attack();
	weapons* playerweapon;
	~heavyweapon();



private:
};

#endif