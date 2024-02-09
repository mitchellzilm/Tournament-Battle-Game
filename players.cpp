#include <iostream>
#include "players.h"
using namespace std;
#include <string>
extern int read_strength_input();
extern int read_speed_input(int strength_input);
extern int read_drip_input(int strength_input, int speed_input);
players::players(){
    name_h = "Null";
    speed_h = 0;
    strength_h = 0;
    drip_h = 0;
}

players::players(string name, int strength, int speed, int drip){
    name_h = name;
    strength_h = strength;
    speed_h = speed;
    drip_h = drip;
}

string players::getName(){
    return name_h;
}

int players::getStrength(){
    return strength_h;
}

int players::getSpeed(){
    return speed_h;
}

int players::getDrip(){
    return drip_h;
}

void players::playerfunction(){
	int sum = 0;
	int count = 15;
	
	cout << "Enter your name: ";
	getline(cin, name_h);
	cout << endl;
	cout << "Welcome " << name_h << endl;
	cout << "Welcome to a competitive fighting simulator where you will be competing against 3 opponents in 3 seperate battles." << endl;
	cout << "Your stats will be important in the overall outcome of your fights so choose them wisely!" << endl;
	cout << "Same goes with your weapon and your armour, these will be crucial to ensure victory." << endl;
	cout << "As you progress, the difficulty of each fight will increase so best of luck to you!" << endl;
	
	strength_h = read_strength_input();
	sum += strength_h;
	count -= strength_h;
	cout <<"Remaining points: "<< count << endl;

	if(count == 0){
		cout << "All points allocated" << endl;
		speed_h = 0;
		drip_h = 0;
		cout << endl;
		
	}else{
		speed_h = read_speed_input(strength_h);
		sum += speed_h;
		count -= speed_h;
		cout << "Remaining Points: " << count << endl;
		if (count == 0){
			drip_h = 0;
			cout << endl;
		}
		else {
			drip_h = read_drip_input(strength_h, speed_h);
			cout << endl;
	    	sum += drip_h;
		}
	}

	if (sum == 15){
	}
	else{
		while (sum != 15){
			drip_h = read_drip_input(strength_h, speed_h);
			sum = speed_h + strength_h + drip_h;
		}
	}
}

players::~players(){
}