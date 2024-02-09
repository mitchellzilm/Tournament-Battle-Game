#include <iostream>
#include <string>
#include "players.h"
#include "weapons.h"
#include "heavyweapon.h"
#include "lightweapon.h"
#include "rangeweapon.h"
using namespace std;
int main(){

// creating the weapon objects 
    heavyweapon* hw1 = new heavyweapon("Sword", 3, 2);
	heavyweapon* hw2 = new heavyweapon("Batttleaxe", 3, 2);
	heavyweapon* hw3 = new heavyweapon("Sickle", 3, 2);
	lightweapon* lw1 = new lightweapon("Dagger", 3, 1);
	lightweapon* lw2 = new lightweapon("Hatchet", 3, 1);
	lightweapon* lw3 = new lightweapon("Machete", 3, 1);
	rangeweapon* rw1 = new rangeweapon("Bow", 3, 1);
	rangeweapon* rw2 = new rangeweapon("Spear", 3, 1);

    //cout << hw1->get_name() << endl;

// putting the weapon objects into an array 
    weapons**over_array_wep=new weapons*[8];
	over_array_wep[0]=hw1;
	over_array_wep[1]=hw2;
	over_array_wep[2]=hw3;
	over_array_wep[3]=lw1;
	over_array_wep[4]=lw2;
	over_array_wep[5]=lw3;
	over_array_wep[6]=rw1;
	over_array_wep[7]=rw2;
	
//the player of the game then has to decide which type of weapon they would like to choose
	cout << "Please choose which type of weapon you would like" << endl;
	cout << "For a heavy weapon, press 1" << endl;
	cout << "For a light weapon, press 2" << endl;
	cout << "For a range weapon, press 3" << endl;

// assigning n as a random variable
	string weap_choice_name;
	int n;
	
//user inputs their selection
	cin >> n;
	cout << endl;

//first if statement that is made is for if the selection is 1 (for a heavyweapon)
	if (n == 1){
	    cout << "You have chosen a heavy weapon." << endl;  
	    cout << "Please select which heavy weapon you would like" << endl; //user again has to chose one of the 3 options available
	    for (int i = 0; i < 3; i++){
	        cout << "For a " << over_array_wep[i]->get_name(); // displays the weapon name options to the user 
	        cout << ", press " << i+1 << endl;
	    }
	    cin >> n; //user inputs their selection, either 1,2 or 3 and their weapon's name is displayed 
	    for (int i = 0; i < 1; i++){
	    	if (n == 1){
	    	cout << "You have chosen a " << over_array_wep[0]->get_name();
	    	cout << " as your weapon" << endl;
	    	}
	    	else if (n == 2){
	    		cout << "You have chosen a " << over_array_wep[1]->get_name();
	    		cout << " as your weapon" << endl;
	    	}
	    	else if (n == 3){
	    		cout << "You have chosen a " << over_array_wep[2]->get_name();
	    		cout << " as your weapon" << endl;
	    	}
			else{
	    		break;
	    	}
	    }
	    
//second if statement that is made is for the selection of 2 (lightweapon)
	}
	else if(n == 2) {
		cout << "You have chosen a light weapon." << endl;
	    cout << "Please select which light weapon you would like" << endl; //once again user selects number between 1 or 3
	    for (int i = 3; i < 2; i++){
	        cout << "For a " << over_array_wep[i]->get_name(); //displays the weapon name options to the user
	        cout << ", press " << i+1 << endl;
	    }
	    //selection is made by the user and the weapon they select is displayed
	    cin >> n;
	    for (int i = 0; i < 1; i++){
	        if (n == 1){
	    		cout << "You have chosen a " << over_array_wep[3]->get_name();
	    		cout << " as your weapon" << endl;
	    	}
	    	else if (n == 2){
        		cout << "You have chosen a " << over_array_wep[4]->get_name();
	    		cout << " as your weapon" << endl;
	    	}
	    	else if (n == 3){
	    		cout << "You have chosen a " << over_array_wep[5]->get_name();
	    		cout << " as your weapon" << endl;
			}
	    	else{
	    		break;
	    	}
	    }
//third if loop is for the selection of a range weapon
	}
	else if (n == 3){
		cout << "You have chosen a range weapon." << endl;
	    cout << "Please select which range weapon you would like" << endl; //same as before user will select which range weapon they would like but only from 1 and 2
	    for (int i = 4; i < 2; i++){
	        cout << "For a " << over_array_wep[i]->get_name(); //range weapons are displayed
	        cout << ", press " << i+1 << endl;
	    }
	    cin >> n; //user makes input and one of the two range weapons is selected and displayed
	    for (int i = 0; i < 1; i++){
	        if (n == 1){
	    		cout << "You have chosen a " << over_array_wep[6]->get_name();
	    		cout << " as your weapon" << endl;
	    	}
	    	else if (n == 2){
	    		cout << "You have chosen a " << over_array_wep[7]->get_name();
	    		cout << " as your weapon" << endl;
	    	}
	    	else {
	    		break;
	    	}	
	    }
	}
// the resulting code should display the final weapon that is chosen in the form 
//"You have chosen a Sword as your weapon" where the Sword is the weapon selected by the user 
}
