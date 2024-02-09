#ifndef rangeweapon_H
#define rangeweapon_H
#include "weapons.h"
#include <string>
using namespace std;


class rangeweapon : public weapons
{
public:
	rangeweapon();
	rangeweapon(string wepname, int damage, int wepcount);
	string *rangeweapon_action();
	int attack();
	~rangeweapon();


private:

};

#endif