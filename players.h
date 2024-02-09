#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;
class players{

private:
string name_h;
int speed_h;
int strength_h;
int drip_h;

public:
    players();
    players(string name, int speed, int strength, int drip);
    void playerfunction();
    string getName();
    int getStrength();
    int getSpeed();
    int getDrip();
    ~players();
};
#endif