#include <iostream>
#include <fstream>
#include <string>
#include "players.h"
#include "weapons.h"
#include "heavyweapon.h"
#include "lightweapon.h"
#include "rangeweapon.h"
#include "Armour.h"
using namespace std;
int main(){

int p8health = 100;                                      //reset this at the start of every battle, easier than setting another player parameter

players p8 = players("don",7 , 0 ,8);
Armour playerarmour = Armour(3, 1, "Leather");
weapons* playerweapon = new heavyweapon("Sword", 20, 2);


players bot = players("Cila Malitz", 5, 2, 8);                           //redefine this at the start of every battle
int bothealth = 100;
Armour botarmour = Armour(3, 1, "Leather");                                   //initialising 1st opponent's gear
weapons* botweapon = new heavyweapon("Sword", 20, 2);

cout << "\n\nThe first battle is beginning! Here is your opponent's description: " <<endl<<endl;        //pre battle 1
cout << "Lv 1 Henchman: " << bot.getName() << endl;
cout << "Health: " << bothealth << endl;
cout << "Armour: " << botarmour.getName() << endl;
cout << "Weapon: " << botweapon->get_name() << endl;
cout << "Strength: " << bot.getStrength() <<endl;
cout << "Speed: " << bot.getSpeed() <<endl;
cout << "Drip: " << bot.getDrip() <<endl<<endl;
cout << "Press 1 to start the epic battle between " << p8.getName() << " and " << bot.getName() << "!" << endl; char contconfirm; cin >> contconfirm;

int arbitraryconst = 0;

while(arbitraryconst==0){
	if(contconfirm=='1'){
		break;
	}
	else{
		cout << "You didn't press 1 but we are continuing anyway haha" <<endl;
		break;
	}	
}

while(p8health>0 && bothealth>0){
	
	int dmgtobot = (playerweapon->attack()+p8.getStrength()-botarmour.getScore());                                                                   //hitting the bot
	bothealth = bothealth-dmgtobot;
	cout << "You hit " << bot.getName() << " for " << dmgtobot << " damage!" <<endl;
	
	if(bothealth>0){                                                                                                                                //dealing damage to the bot
		cout << bot.getName() << "'s remaining health: " << bothealth << endl;
		cout << "Press 1 to finish your turn" << endl; cin >> contconfirm;
		while(arbitraryconst==0){
			if(contconfirm=='1'){
				break;
			}
			else{
				cout << "You didn't press 1 but we are continuing anyway haha" <<endl;
				break;
			}
		}
	}
	else if(bothealth<=0){                                                                                                                              // killing the bot
		cout << "You struck " << bot.getName() << " so hard they fell over and died." << endl;
		cout << "You won! Press 1 to continue to the next battle" << endl; cin >> contconfirm;
		while(arbitraryconst==0){
			if(contconfirm=='1'){
				break;
			}
			else{
				cout << "You didn't press 1 but we are continuing anyway haha" <<endl;
				break;
			}
		}
	}
	
	int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore());
	p8health = p8health-dmgtoplayer;                                                                             //bot hitting player
	cout << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;
	
	if(p8health>0){
		cout << p8.getName() << "'s remaining health: " << p8health << endl;                                        //dealing damage to plaer
		cout << "Press 1 to start your turn now" << endl; cin >> contconfirm;
		while(arbitraryconst==0){
			if(contconfirm=='1'){
					break;
			}
			else{
				cout << "You didn't press 1 but we are continuing anyway haha" <<endl;
				break;
			}
		}
	}

	else if(p8health<=0){                                                                                      //killing player
		cout << bot.getName() << " killed you really hard stupido and you died." << endl;
		cout << "Press 1 to quit" << endl; cin >> contconfirm;
		while(arbitraryconst==0){
			if(contconfirm=='1'){
					break;
			}
			else{
				cout << "You didn't press 1 but we are continuing anyway haha" <<endl;
				break;
			}
		}
	}
}
}