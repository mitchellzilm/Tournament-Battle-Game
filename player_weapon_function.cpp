#include <iostream>
#include <fstream>
#include <string>
#include "weapons.h"
#include "heavyweapon.h"
#include "lightweapon.h"
#include "rangeweapon.h"
using namespace std;
extern int weapon_type_select();
string getFileContents (ifstream&);

string getFileContents (ifstream& artFile)
{
    string art = " ";
    
    if (artFile)                      
    {
    while (artFile.good ())
    {
        string spacingLine;                  
        getline (artFile , spacingLine);       
        spacingLine += "\n";                      
        
        art += spacingLine;                     
    }
    return art;
    }
    else                           
    {
    return "ERROR artFile does not exist.";
    }
}

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
