#ifndef WEAPONS_H
#define WEAPONS_H
#include <string>
using namespace std;


class weapons
{
public:
	weapons();
	weapons(string wepname, int damage, int wepcount);
	weapons* playerweapon;
	string get_name();
	int get_damage();
	int get_wepcount();

	virtual int attack()=0;            //week11 Tues virtual func

	~weapons();

protected:
	string namewep;
	int dmgwep;
	int countwep;
};

#endif