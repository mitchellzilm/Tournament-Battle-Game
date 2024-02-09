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
extern int weapon_function();
extern int armourChoice();
extern int choice();
using namespace std;

void battle_function(string userName, int userStrength, int userSpeed, int userDrip, int wepChoice, int armChoice){
	
    players p1, p2, p3, p8;
	p1 = players("Cila Malitz", 5, 2, 8);
	p2 = players("Tachel Rang", 1, 8, 6);
	p3 = players("Yuddlie Du", 11, 1, 3);
	p8 = players(userName, userStrength , userSpeed , userDrip);
	
    Armour playerarmour;                                                                 //initialise player gear. i will try to define this as whatever the player chooses
    weapons* playerweapon;

    heavyweapon* hw1 = new heavyweapon("Sword", 20, 2);
    heavyweapon* hw2 = new heavyweapon("Battleaxe", 20, 2);
    heavyweapon* hw3 = new heavyweapon("Sickle", 20, 2);
    lightweapon* lw1 = new lightweapon("Dagger", 22, 1);
    lightweapon* lw2 = new lightweapon("Hatchet", 22, 1);
    lightweapon* lw3 = new lightweapon("Machete", 22, 1);
    rangeweapon* rw1 = new rangeweapon("Bow", 10, 1);
    rangeweapon* rw2 = new rangeweapon("Spear", 10, 1);

    weapons**over_array_wep=new weapons*[8];
    over_array_wep[0]=hw1;
    over_array_wep[1]=hw2;
    over_array_wep[2]=hw3;
    over_array_wep[3]=lw1;
    over_array_wep[4]=lw2;
    over_array_wep[5]=lw3;
    over_array_wep[6]=rw1;
    over_array_wep[7]=rw2;
    
    Armour a[6]={
		Armour(3, 1, "Leather"),
		Armour(4, 1, "Gold"),
		Armour(5, 1, "Chain"),
		Armour(6, 2, "Diamond"),
		Armour(7, 2, "Iron"),
		Armour(8, 2, "Netherite")};

   playerarmour = a[armChoice - 1];
   playerweapon = over_array_wep[wepChoice];
   cout << "Here is your loadout: " << endl;
	cout << "Armour: " << playerarmour.getName() << endl;
	cout << "Weapon: " << playerweapon->get_name() << endl;
	cout << "Strength: " << p8.getStrength() <<endl;
	cout << "Speed: " << p8.getSpeed() <<endl;
	cout << "Drip: " << p8.getDrip() <<endl<<endl;
	cout << "Press 1 to continue..." << endl; 
    cout << "Press 2 to exit the game" << endl;
	int arbitraryconst = 0;
	int n = choice();
	while(arbitraryconst==0){
		if(n == 1){
			break;
		}
		else{
			cout << "Thanks for playing!" << endl;                      //loop for accepting key press to continue
			exit (0);
		}
    }
   
    int p8health = 100; //resets at start of every battle

    players bot = p1;                              //redefine this at the start of every battle
	int bothealth = 100;
	Armour botarmour = a[0];                                   //initialising 1st opponent's gear
	weapons* botweapon = lw1;

	cout << "\n\nThe first battle is beginning! Here is your opponent's description: " <<endl<<endl;        //pre battle 1
	cout << "Lv 1 Henchman: " << bot.getName() << endl;

	if(p8.getDrip() == bot.getDrip()){
		cout << "Health: " << bothealth << endl;
	}
	else if(p8.getDrip() > bot.getDrip()){
		cout << "\nThe sight of your bedazzling drip reduced the opponent's health by half!" << endl;
		cout << "Initial Health: " << bothealth << endl;
		bothealth = bothealth/2;
		cout << "Dripped Health: " << bothealth << endl <<endl;
	}
	else if(p8.getDrip() < bot.getDrip()){
		cout << "\nYou have been blinded by your opponents imaculate drip! Your health has been decreased!" << endl;
		cout << "Initial Health: " << p8health << endl;
		p8health = p8health/1.25;
		cout << "Dripped Health: " << p8health << endl <<endl;
	}


	cout << "Armour: " << botarmour.getName() << endl;
	cout << "Weapon: " << botweapon->get_name() << endl;
	cout << "Strength: " << bot.getStrength() <<endl;
	cout << "Speed: " << bot.getSpeed() <<endl;
	cout << "Drip: " << bot.getDrip() <<endl<<endl;
	cout << "Press 1 to start the epic battle between " << p8.getName() << " and " << bot.getName() << "!" << endl; 
	cout << "Press 2 to quit" << endl;
    arbitraryconst = 0;
	n = choice();
	while(arbitraryconst==0){
		if(n == 1){
			break;
		}
		else{
			cout << "Thanks for playing!" << endl;                      //loop for accepting key press to continue
			exit(0);
		}
    }
	while(p8health>0 && bothealth>0){             //1st fight!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(p8.getSpeed() >= bot.getSpeed()){																												//if user is faster they move first
			int dmgtobot = (playerweapon->attack()+p8.getStrength()-botarmour.getScore());                                                                   //hitting the bot
			bothealth = bothealth-dmgtobot;
			cout << "\nYou hit " << bot.getName() << " for " << dmgtobot << " damage!" <<endl;
		
		if(bothealth>0){                                                                                                                                //dealing damage to the bot
			cout << bot.getName() << "'s remaining health: " << bothealth << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "Press 1 for your opponent to take their turn" << endl; 
			cout << "Press 2 to block (choose with caution)" << endl;
			n = choice();
			cout << endl;
			while(arbitraryconst==0){
				if(n == 1){				   //loop for accepting key press to continue
					break;
				}
				else{                   
					cout << "You have chosen to block!" << endl;
					break;
				}
    		}
		}

		else if(bothealth<=0){                                                                                                                              // killing the bot
			cout << "You struck " << bot.getName() << " so hard they fell over and died." << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "You won! Press 1 to continue to the next battle" << endl; 
			cout << "Press 2 to quit" << endl;
			n = choice();
			while(arbitraryconst==0){
				if(n == 1){
					break;
				}
				else{
					cout << "Thanks for playing!" << endl;                      //loop for accepting key press to continue
					exit(0);
				}
    		}
		}

		if(bothealth>0){ //this if loop prevents the bot from hitting the player if it has just been killed
			if (n == 1){
				int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore());
				p8health = p8health-dmgtoplayer;                                                                             //bot hitting player
				cout << "\n" << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;

			}
			else if (n == 2){ 
				int random = (rand() % 2) + 1;
				if (random == 1){
					cout << "Your block was successful! You have taken no damage!" << endl;
					int dmgtoplayer = 0;
					p8health =  p8health-dmgtoplayer;
					
				}else {
					cout << "Your block was unsuccessful! You have taken an extra 15 damage!";
					int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore())+15;
					p8health = p8health-dmgtoplayer;                                                                             //bot hitting player
					cout << "\n" << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;
				}
			}
			if(p8health>0){
				cout << bot.getName() << "'s remaining health: " << bothealth << endl;
				cout << p8.getName() << "'s remaining health: " << p8health << endl;                                        //dealing damage to plaer
				cout << "Press 1 to take your turn now" << endl; 
				cout << "Press 2 to retire" << endl;
				n = choice();
				while(arbitraryconst==0){
					if(n == 1){
						break;
					}
					else{
						cout << "You have chosen to retire." << endl;                      //loop for accepting key press to continue
						exit (0);
					}
    			}
			}

			else if(p8health<=0){                                                                                      //killing player
				cout << bot.getName() << " killed you really hard stupido and you died." << endl;
				cout << bot.getName() << "'s remaining health: " << bothealth << endl;
				cout << "Press 1 to quit" << endl; 
				n = choice();
				while(arbitraryconst==0){
					if(n == 1){
					exit (0);
					}
    			}
			}
		}
		else if(bothealth<=0){
			break;
		}
		}

	else if(bot.getSpeed() > p8.getSpeed()){ //case for if bot is faster, they move first
			if (n == 1){
			int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore());
			p8health = p8health-dmgtoplayer;
			cout << "\n" << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;
		}
		else if (n == 2){ 
			int random = (rand() % 2) + 1;
			if (random == 1){
				cout << "Your block was successful! You have taken no damage" << endl;
				int dmgtoplayer = 0;
				p8health =  p8health-dmgtoplayer;
					
			}
			else{
				cout << "Your block was unsuccessful! ";
				int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore())+15;
				p8health = p8health-dmgtoplayer;                                                                             //bot hitting player
				cout << "\n" << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;
			}
		}
		
		if(p8health>0){
			cout << bot.getName() << "'s remaining health: " << bothealth << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "Press 1 to take your turn now" << endl; 
			cout << "Press 2 to retire" << endl;
			n = choice();
			while(arbitraryconst==0){
				if(n == 1){
					break;
				}
				else{
					cout << "You have chosen to retire." << endl;                      //loop for accepting key press to continue
					exit (0);
				}
			}
		}

			else if(p8health<=0){
				cout << bot.getName() << " killed you really hard stupido and you died." << endl;
				cout << bot.getName() << "'s remaining health: " << bothealth << endl;
				cout << "Press 1 to quit" << endl; 
				n = choice();
				while(arbitraryconst==0){
					if(n == 1){
						exit(0);
					}
    			}
			}
		if(p8health>0){
				int dmgtobot = (playerweapon->attack()+p8.getStrength()-botarmour.getScore());                                                                   //hitting the bot
				bothealth = bothealth-dmgtobot;
				cout << "\nYou hit " << bot.getName() << " for " << dmgtobot << " damage!" << endl;
			
		}

		if(bothealth>0){
			cout << bot.getName() << "'s remaining health: " << bothealth << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "Press 1 for your opponent to take their turn" << endl; 
			cout << "Press 2 to block (proceed with caution)" << endl;
			n = choice();
			while(arbitraryconst==0){
				if(n == 1){
					break;
				}
				else{
				    cout << "You have chosen to block!" << endl;
					break;
				}
    		}
		}

		else if(bothealth<=0){
			cout << "You struck " << bot.getName() << " so hard they fell over and died." << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "You won! Press 1 to continue to the next battle" << endl; 
			cout << "Press 2 to exit" << endl;
			n = choice();
			while(arbitraryconst==0){
				if(n == 1){
					break;
				}
				else{
					cout << "Thanks for playing!" << endl;                      //loop for accepting key press to continue
					exit (0);
				}
    		}
		}

	}
}


	p8health = 100;                                      //reset this at the start of every battle, easier than setting another player parameter

    bot = p2;                              //redefine this at the start of every battle
	bothealth = 110;
	botarmour = a[4];                                   //initialising 1st opponent's gear
	botweapon = rw2;

	cout << "\n\nThe second battle is beginning! Here is your opponent's description: " <<endl<<endl;        //pre battle 1
	cout << "Lv 10 Crook: " << bot.getName() << endl;

	if(p8.getDrip() == bot.getDrip()){
		cout << "Health: " << bothealth << endl;
	}
	else if(p8.getDrip() > bot.getDrip()){
		cout << "\nThe sight of your bedazzling drip reduced the opponent's health by half!" << endl;
		cout << "Initial Health: " << bothealth << endl;
		bothealth = bothealth/2;
		cout << "Dripped Health: " << bothealth << endl <<endl;
	}
	else if(p8.getDrip() < bot.getDrip()){
		cout << "\nYou have been blinded by your opponents imaculate drip! Your health has been decreased!" << endl;
		cout << "Initial Health: " << p8health << endl;
		p8health = p8health/1.25;
		cout << "Dripped Health: " << p8health << endl <<endl;
	}

	cout << "Armour: " << botarmour.getName() << endl;
	cout << "Weapon: " << botweapon->get_name() << endl;
	cout << "Strength: " << bot.getStrength() <<endl;
	cout << "Speed: " << bot.getSpeed() <<endl;
	cout << "Drip: " << bot.getDrip() <<endl<<endl;
	cout << "Press 1 to start the epic battle between " << p8.getName() << " and " << bot.getName() << "!" << endl;
	cout << "Press 2 to exit" << endl;
	n = choice();
	while(arbitraryconst==0){
		if(n == 1){
			break;
		}
		else{
			cout << "Thanks for playing!" << endl;                      //loop for accepting key press to continue
			exit (0);
			}
    }

	while(p8health > 0 && bothealth > 0){                                                                                       //2ndfight!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(p8.getSpeed() >= bot.getSpeed()){																												//if user is faster they move first
	    int dmgtobot = (playerweapon->attack()+p8.getStrength()-botarmour.getScore());                                                                   //hitting the bot
		bothealth = bothealth-dmgtobot;

		cout << "\nYou hit " << bot.getName() << " for " << dmgtobot << " damage!" <<endl;

		if(bothealth>0){                                                                                                                                //dealing damage to the bot
			cout << bot.getName() << "'s remaining health: " << bothealth << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "Press 1 for your opponent to take their turn" << endl; 
			cout << "Press 2 to block (proceed with caution)" << endl;
			n = choice();
			while(arbitraryconst==0){
				if(n == 1){
					break;
				}
				else{
					cout << "You have chosen to block!" << endl;                      //loop for accepting key press to continue
					break;
				}
    		}
		}

		else if(bothealth<=0){                                                                                                                              // killing the bot
			cout << "You struck " << bot.getName() << " so hard they fell over and died." << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "You won! Congratulations! You have made it to the final battle!" << endl;
			cout << "Press 1 to continue" << endl;
			cout << "Press 2 to quit" << endl;
			n = choice();
			while(arbitraryconst==0){
				if(n == 1){
					break;
				}
				else{                      //loop for accepting key press to continue
					exit (0);
				}
    		}
		}

		if(bothealth>0){                                                                                               //this if loop prevents the bot from hitting the player if it has just been killed
			if (n == 1){
				int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore());
				p8health = p8health-dmgtoplayer;
				cout << "\n" << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;
			}
			else if (n == 2){ 
				int random = (rand() % 2) + 1;
				if (random == 1){
					cout << "Your block was successful! You have taken no damage" << endl;
					int dmgtoplayer = 0;
					p8health =  p8health-dmgtoplayer;
				}
				else{
					cout << "Your block was unsuccessful! ";
					int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore())+15;
					p8health = p8health-dmgtoplayer;                                                                             //bot hitting player
					cout << "\n" << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;
				}
			}

			if(p8health>0){
				cout << bot.getName() << "'s remaining health: " << bothealth << endl;
				cout << p8.getName() << "'s remaining health: " << p8health << endl;                                        //dealing damage to plaer
				cout << "Press 1 to take your turn now" << endl; 
				cout << "Press 2 to retire" << endl;
				n = choice();
				while(arbitraryconst==0){
					if(n == 1){
						break;
					}
					else{
						cout << "You have chosen to retire." << endl;                      //loop for accepting key press to continue
						exit(0);
					}
    			}
			}

			else if(p8health<=0){                                                                                      //killing player
				cout << bot.getName() << " killed you really hard stupido and you died." << endl;
				cout << bot.getName() << "'s remaining health: " << bothealth << endl;
				cout << "Press 1 to quit" << endl; 
				n = choice();
				while(arbitraryconst==0){
					if(n == 1){
						exit (0);
					}
					else{
						cout << "Thanks for playing!" << endl;                      //loop for accepting key press to continue
						exit(0);
					}
    			}	
			}
		}
		else if(bothealth<=0){
			break;
		}


	}
	else if(bot.getSpeed() > p8.getSpeed()){                                                                                     //case for if bot is faster, they move first
		if (n == 1){
			int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore());
			p8health = p8health-dmgtoplayer;
			cout << "\n" << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;
		}
		else if (n == 2){ 
			int random = (rand() % 2) + 1;
			if (random == 1){
				cout << "Your block was successful! You have taken no damage" << endl;
				int dmgtoplayer = 0;
				p8health =  p8health-dmgtoplayer;
					
			}
			else{
				cout << "Your block was unsuccessful! ";
				int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore())+15;
				p8health = p8health-dmgtoplayer;                                                                             //bot hitting player
				cout << "\n" << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;
			}
		}
	
			if(p8health>0){
				cout << bot.getName() << "'s remaining health: " << bothealth << endl;
				cout << p8.getName() << "'s remaining health: " << p8health << endl;
				cout << "Press 1 to take your turn now" << endl; 
				cout << "Press 2 to retire" << endl;
				n = choice();
				while(arbitraryconst==0){
					if(n == 1){
						break;
					}
					else{
						cout << "You have chosen to retire." << endl;                      //loop for accepting key press to continue
						exit (0);
					}
    			}
			}

			else if(p8health<=0){
				cout << bot.getName() << " killed you really hard stupido and you died." << endl;
				cout << bot.getName() << "'s remaining health: " << bothealth << endl;
				cout << "Press 1 to quit" << endl; 
				n = choice();
				while(arbitraryconst==0){
					if(n == 1){
						break;
					}
					else{
						cout << "Thanks for playing!" << endl;                      //loop for accepting key press to continue
						exit (0);
					}
    			}
			}
		if(p8health>0){
		int dmgtobot = (playerweapon->attack()+p8.getStrength()-botarmour.getScore());
		bothealth = bothealth-dmgtobot;

		cout << "\nYou hit " << bot.getName() << " for " << dmgtobot << " damage!" <<endl;

		if(bothealth>0){
			cout << bot.getName() << "'s remaining health: " << bothealth << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "Press 1 for your opponent to take their turn" << endl; 
			cout << "Press 2 to block (proceed with caution)" << endl;
			n = choice();
			while(arbitraryconst==0){
				if(n == 1){
					break;
				}
				else{
					cout << "You have chosen to block!" << endl;                      //loop for accepting key press to continue
					break;
				}
    		}
		}

		else if(bothealth<=0){
			cout << "You struck " << bot.getName() << " so hard they fell over and died." << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "You won! Congratulations! You have made it too the final battle!" << endl;
			cout << "Press 1 to continue" << endl;
			cout << "Press 2 to quit" << endl;
			n = choice();
			while(arbitraryconst==0){
				if(n == 1){
					break;
				}
				else{                      //loop for accepting key press to continue
					exit(0);
				}
    		}
		}

	}
	}

	}
	p8health = 100;                                      //reset this at the start of every battle, easier than setting another player parameter

    bot = p3;                              //redefine this at the start of every battle
	bothealth = 200;
	botarmour = a[5];                                   //initialising 1st opponent's gear
	botweapon = hw2;

	cout << "\n\nThe final battle is beginning! Here is your opponent's description: " <<endl<<endl;        //pre battle 1
	cout << "Lv 100 Mafia Boss: " << bot.getName() << endl;

	if(p8.getDrip() == bot.getDrip()){
		cout << "Health: " << bothealth << endl;
	}
	else if(p8.getDrip() > bot.getDrip()){
		cout << "\nThe sight of your bedazzling drip reduced the opponent's health by a fifth!" << endl;
		cout << "Initial Health: " << bothealth << endl;
		bothealth = bothealth/1.25;
		cout << "Dripped Health: " << bothealth << endl <<endl;
	}
	else if(p8.getDrip() < bot.getDrip()){
		cout << "\nYou have been blinded by your opponents imaculate drip! Your health has been cut by half!" << endl;
		cout << "Initial Health: " << p8health << endl;
		p8health = p8health/2;
		cout << "Dripped Health: " << p8health << endl <<endl;
	}

	cout << "Armour: " << botarmour.getName() << endl;
	cout << "Weapon: " << botweapon->get_name() << endl;
	cout << "Strength: " << bot.getStrength() <<endl;
	cout << "Speed: " << bot.getSpeed() <<endl;
	cout << "Drip: " << bot.getDrip() <<endl<<endl;
	cout << "Press 1 to start the epic battle between " << p8.getName() << " and " << bot.getName() << "!" << endl;
	cout << "Press 2 to exit" << endl;
	n = choice();
	while(arbitraryconst==0){
		if(n == 1){
			break;
		}
		else{
			cout << "Thanks for playing!" << endl;                      //loop for accepting key press to continue
			exit (0);
			}
    }

	while(p8health>0 && bothealth>0){                                                                                       //2ndfight!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(p8.getSpeed() >= bot.getSpeed()){																												//if user is faster they move first

	    int dmgtobot = (playerweapon->attack()+p8.getStrength()-botarmour.getScore());                                                                   //hitting the bot
		bothealth = bothealth-dmgtobot;

		cout << "\nYou hit " << bot.getName() << " for " << dmgtobot << " damage!" <<endl;

		if(bothealth>0){                                                                                                                                //dealing damage to the bot
			cout << bot.getName() << "'s remaining health: " << bothealth << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "Press 1 for your opponent to take their turn" << endl; 
			cout << "Press 2 to block (proceed with caution)" << endl;
			n = choice();
			while(arbitraryconst==0){
				if(n == 1){
					break;
				}
				else{
					cout << "You have chosen to block!" << endl;                      //loop for accepting key press to continue
					break;
				}
    		}
		}

		else if(bothealth<=0){                                                                                                                              // killing the bot
			cout << "You struck " << bot.getName() << " so hard they fell over and died." << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "You won! Congratulations! Press 1 to end" << endl; 
			n = choice();
			while(arbitraryconst==0){
				if(n == 1){
					exit (0);
				}
				else{
					exit (0);
				}
    		}
		}

		if(bothealth>0){                                                                                               //this if loop prevents the bot from hitting the player if it has just been killed
			if (n == 1){
				int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore());
				p8health = p8health-dmgtoplayer;
				cout << "\n" << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;
			}
			else if (n == 2){ 
				int random = (rand() % 2) + 1;
				if (random == 1){
					cout << "Your block was successful! You have taken no damage" << endl;
					int dmgtoplayer = 0;
					p8health =  p8health-dmgtoplayer;
				}
				else{
					cout << "Your block was unsuccessful! ";
					int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore())+15;
					p8health = p8health-dmgtoplayer;                                                                             //bot hitting player
					cout << "\n" << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;
				}
			}

			if(p8health>0){
				cout << bot.getName() << "'s remaining health: " << bothealth << endl;
				cout << p8.getName() << "'s remaining health: " << p8health << endl;                                        //dealing damage to plaer
				cout << "Press 1 to take your turn now" << endl; 
				cout << "Press 2 to retire" << endl;
				n = choice();
				while(arbitraryconst==0){
					if(n == 1){
						break;
					}
					else{
						cout << "You have chosen to retire." << endl;                      //loop for accepting key press to continue
						exit(0);
					}
    			}
			}

			else if(p8health<=0){                                                                                      //killing player
				cout << bot.getName() << " killed you really hard stupido and you died." << endl;
				cout << bot.getName() << "'s remaining health: " << bothealth << endl;
				cout << "Press 1 to quit" << endl; 
				n = choice();
				while(arbitraryconst==0){
					if(n == 1){
						exit (0);
					}
					else{
						cout << "Thanks for playing!" << endl;                      //loop for accepting key press to continue
						exit(0);
					}
    			}	
			}
		}
		else if(bothealth<=0){
			break;
		}


	}
	else if(bot.getSpeed() > p8.getSpeed()){                                                                                     //case for if bot is faster, they move first
		if (n == 1){
			int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore());
			p8health = p8health-dmgtoplayer;
			cout << "\n" << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;
		}
		else if (n == 2){ 
			int random = (rand() % 2) + 1;
			if (random == 1){
				cout << "Your block was successful! You have taken no damage" << endl;
				int dmgtoplayer = 0;
				p8health =  p8health-dmgtoplayer;
					
			}
			else{
				cout << "Your block was unsuccessful! ";
				int dmgtoplayer = (botweapon->attack()+bot.getStrength()-playerarmour.getScore())+15;
				p8health = p8health-dmgtoplayer;                                                                             //bot hitting player
				cout << "\n" << bot.getName()<< " hit you"  << " for " << dmgtoplayer << " damage!" <<endl;
			}
		}
	
			if(p8health>0){
				cout << bot.getName() << "'s remaining health: " << bothealth << endl;
				cout << p8.getName() << "'s remaining health: " << p8health << endl;
				cout << "Press 1 to take your turn now" << endl; 
				cout << "Press 2 to retire" << endl;
				n = choice();
				while(arbitraryconst==0){
					if(n == 1){
						break;
					}
					else{
						cout << "You have chosen to retire." << endl;                      //loop for accepting key press to continue
						exit (0);
					}
    			}
			}

			else if(p8health<=0){
				cout << bot.getName() << " killed you really hard stupido and you died." << endl;
				cout << bot.getName() << "'s remaining health: " << bothealth << endl;
				cout << "Press 1 to quit" << endl; 
				n = choice();
				while(arbitraryconst==0){
					if(n == 1){
						break;
					}
					else{
						cout << "Thanks for playing!" << endl;                      //loop for accepting key press to continue
						exit (0);
					}
    			}
			}
		if(p8health>0){
		int dmgtobot = (playerweapon->attack()+p8.getStrength()-botarmour.getScore());
		bothealth = bothealth-dmgtobot;

		cout << "\nYou hit " << bot.getName() << " for " << dmgtobot << " damage!" <<endl;

		if(bothealth>0){
			cout << bot.getName() << "'s remaining health: " << bothealth << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "Press 1 for your opponent to take their turn" << endl; 
			cout << "Press 2 to block (proceed with caution)" << endl;
			n = choice();
			while(arbitraryconst==0){
				if(n == 1){
					break;
				}
				else{
					cout << "You have chosen to block!" << endl;                      //loop for accepting key press to continue
					break;
				}
    		}
		}

		else if(bothealth<=0){
			cout << "You struck " << bot.getName() << " so hard they fell over and died." << endl;
			cout << p8.getName() << "'s remaining health: " << p8health << endl;
			cout << "You won! Congratulations! Press 1 to end" << endl;
			n = choice();
			while(arbitraryconst==0){
				if(n == 1){
					exit (0);
				}
				else{                      //loop for accepting key press to continue
					exit (0);
				}
    		}
		}

	}
	}

	}

}