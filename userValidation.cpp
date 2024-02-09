#include <stdlib.h>
#include <iostream>
using namespace std;

// first function will validate the user strength and prevent the user from entering
// any value that isnt between 
int read_strength_input(){
    int strength_input;
    int count = 15;
    cout << "Enter your desired strength between 0 and 15: ";
    bool valid = false;
    while (! valid){
    cin >> strength_input;
        if(cin.fail()){
            cin.clear();
            cin.ignore (16, '\n');
            cout << "This input is invalid" << endl;
            cout << "Enter a value between 0 and 15: ";
        }else {
            valid = true;
        }

    }
    while(strength_input > 15 || strength_input < 0){
        cout << "This input is invalid" << endl;
        cout << "Enter a value between 0 and 15: ";
        cin >> strength_input;
        while(cin.fail()){
            cin.clear();
            cin.ignore (16, '\n');
            cout << "This input is invalid" << endl;
            cout << "Enter a value between 0 and 15: ";
            cin >> strength_input;
        }
    }
    return strength_input;
    
}
int read_speed_input(int strength_input){
    int speed_input;
    int count = 15 - strength_input;
    cout << "Enter your desired speed between 0 and " << count << ": ";
    bool valid = false;
    while (! valid){
    cin >> speed_input;
        if(cin.fail()){
            cin.clear();
            cin.ignore (16, '\n');
            cout << "This input is invalid" << endl;
            cout << "Enter a value between 0 and " << count << ": ";
        }else {
            valid = true;
        }

    }
    while(speed_input > count || speed_input < 0){
        cout << "This input is invalid" << endl;
        cout << "Enter a value between 0 and " << count << ": ";
        cin >> speed_input;
        while(cin.fail()){
            cin.clear();
            cin.ignore (16, '\n');
            cout << "This input is invalid" << endl;
            cout << "Enter a value between 0 and " << count << ": ";
            cin >> speed_input;
        }
    }
    return speed_input;
}

int read_drip_input(int strength_input, int speed_input){
    int drip_input;
    int count = 15 - strength_input - speed_input;
    cout << "Enter your desired drip of " << count << " for your drip: ";
    bool valid = false;
    while (! valid){
    cin >> drip_input;
        if(cin.fail()){
            cin.clear();
            cin.ignore (16, '\n');
            cout << "This input is invalid" << endl;
            cout << "Enter a value of " << count << " for your drip: ";
        }else {
            valid = true;
        }

    }
    while(drip_input > count || drip_input < 0){
        cout << "This input is invalid" << endl;
        cout << "Enter a value of " << count << " for your drip: ";
        cin >> drip_input;
        while(cin.fail()){
            cin.clear();
            cin.ignore (16, '\n');
            cout << "This input is invalid" << endl;
            cout << "Enter a value of " << count << " for your drip: ";
            cin >> drip_input;
        }
    }
    return drip_input;
}

int weapon_type_select(){
    int n;
    int arb = 0;
    bool valid = false;
    while (! valid){
    cin >> n;
        if(cin.fail()){
            cin.clear();
            cin.ignore (4, '\n');
            cout << "This input is invalid" << endl;
            cout << "Please choose 1,2 or 3: ";
        }else {
            valid = true;
        }

    }
    while(arb == 0){
        if(n == 1 || n == 2 || n == 3){
            return n;
        }
        else{
            cout << "This input is invalid" << endl;
            cout << "Please choose either 1, 2 or 3: ";
            cin >> n;
            while(cin.fail()){
                cin.clear();
                cin.ignore (4, '\n');
                cout << "This input is invalid" << endl;
                cout << "Please choose either 1, 2 or 3: ";
                cin >> n;
            }
        }
    }
    return n;
}

int armour_type_select(){
    int n;
    int arb = 0;
    bool valid = false;
    while (! valid){
    cin >> n;
        if(cin.fail()){
            cin.clear();
            cin.ignore (7, '\n');
            cout << "This input is invalid" << endl;
            cout << "Please choose a value from 1-6: ";
        }else {
            valid = true;
        }

    
    }
    while(arb == 0){
        if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5 || n == 6){
            break;
        }
        else {
        cout << "This input is invalid" << endl;
        cout << "Please choose a value from 1-6: ";
        cin >> n;
        cout << endl;
        while(cin.fail()){
            cin.clear();
            cin.ignore (7, '\n');
            cout << "This input is invalid" << endl;
            cout << "Please choose a value from 1-6: ";
            cin >> n;
            cout << endl;
        }
    }
        }
    return n;
}

int choice(){
    int n;
    int arb = 0;
    bool valid = false;
    while (! valid){
    cin >> n;
        if(cin.fail()){
            cin.clear();
            cin.ignore (3, '\n');
            cout << "This input is invalid" << endl;
            cout << "Please choose 1 or 2: ";
        }else {
            valid = true;
        }

    }
    while(arb == 0){
        if(n == 1 || n == 2){
            break;
        }
        else{
            cout << "This input is invalid" << endl;
            cout << "Please choose either 1 or 2: ";
            cin >> n;
            while(cin.fail()){
                cin.clear();
                cin.ignore (3, '\n');
                cout << "This input is invalid" << endl;
                cout << "Please choose either 1 or 2: ";
                cin >> n;
            }   
        }
    }
    return n;
}