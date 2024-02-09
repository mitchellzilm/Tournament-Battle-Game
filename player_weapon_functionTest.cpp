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
extern int weapon_type_select();

int weapon_function(){
	string weapons_array[8] = {"Sword","Battleaxe","Sickle","Dagger","Hatchet","Machete","Bow","Spear"};
	cout << "Please choose which type of weapon you would like" << endl;
    cout << "For a heavy weapon, press 1" << endl;
    ifstream hwAscii ("File1.txt");
    string artHw = getFileContents (hwAscii);
    cout << artHw << std::endl;
    hwAscii.close ();
    cout << "For a light weapon, press 2" << endl;
    ifstream lwAscii ("File2.txt");
    string artLw = getFileContents (lwAscii);
    cout << artLw << std::endl;
    lwAscii.close ();
    cout << "For a range weapon, press 3" << endl;
    ifstream rwAscii ("File3.txt");
    string artRw = getFileContents (rwAscii);
    cout << artRw << std::endl;
    rwAscii.close ();
    cout<<"\n"<<endl;

	int n = weapon_type_select();
    if (n == 1){
    	cout << "You have chosen a heavy weapon." << endl;
    	cout << endl;
    	cout << "Please select which heavy weapon you would like" << endl;
    	for (int i = 0; i < 3; i++){
    		cout << "For a " << weapons_array[i];
    		cout << ", press " << i+1 << endl;
    	}
        int m = weapon_type_select();
    	for (int i = 0; i < 1; i++){
    		if (m == 1){                                                              //define playerweapon
    			cout << "You have chosen a " << weapons_array[0];
    			cout << " as your weapon" << endl;
    			cout << endl;
    			return 0;

    		}else if (m == 2){
    			cout << "You have chosen a " << weapons_array[1];
    			cout << " as your weapon" << endl;
    			cout << endl;
    			return 1;
    		}else if (m == 3){
    			cout << "You have chosen a " << weapons_array[2];
    			cout << " as your weapon" << endl;
    			cout << endl;
    		    return 2;
    		}else {
    			break;
    		}
        }
   
    }
    else if(n == 2){cout << "You have chosen a light weapon." << endl;
    	cout << endl;
    	cout << "Please select which light weapon you would like" << endl;
    	for (int i = 3; i < 6; i++){
    		cout << "For " << weapons_array[i];
    		cout << ", press " << i-2 << endl;
    	}
    	int m = weapon_type_select();
    	for (int i = 0; i < 1; i++){
    		if (m == 1){
    			cout << "You have chosen a " << weapons_array[3];
    			cout << " as your weapon" << endl;
    			cout << endl;
    			return 3;
    		}else if (m == 2){
    			cout << "You have chosen a " << weapons_array[4];
    			cout << " as your weapon" << endl;
    			cout << endl;
    			return 4;
    		}else if (m == 3){
    			cout << "You have chosen a " << weapons_array[5];
    			cout << " as your weapon" << endl;
    			return 5;
    		}else {
    			break;
    		}
        }

	}
	else if (n == 3){cout << "You have chosen a range weapon." << endl;
		cout << endl;
		cout << "Please select which range weapon you would like" << endl;
		for (int i = 6; i < 8; i++){
			cout << "For a " << weapons_array[i];
			cout << ", press " << i-5 << endl;
		}
		int m = weapon_type_select();
		for (int i = 0; i < 1; i++){
			if (n == 1){
				cout << "You have chosen " << weapons_array[6];
				cout << " as your weapon" << endl;
				cout << endl;
				return 6;
			}else if (n == 2){
				cout << "You have chosen " << weapons_array[7];
				cout << " as your weapon" << endl;
				cout << endl;
				return 7;
			}else {
				break;
			}
		}
	}
return 0;
}

int main(){
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

	int m = weapon_function();
	playerweapon = over_array_wep[m];
}