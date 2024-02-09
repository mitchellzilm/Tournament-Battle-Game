#include <iostream>
#include <string>
#include "Armour.h"

using namespace std;

//READ - I've compiled this test file and Armour.cpp as "swag". In the command line enter "./swag < input1.txt > output1.txt", this generates output1 in the folder which you can open to look at the test results. Do the same for input2.txt.
// It's a pretty trivial use of I/O automating but i'm sure it can be useful later down the line

int main(){
    int choice = 0;

    Armour playerchoice;

    Armour a[6]={
    Armour(1, 1, "Leather"),
    Armour(2, 1, "Gold"),
    Armour(3, 1, "Chain"),
    Armour(4, 2, "Diamond"),
    Armour(5, 2, "Iron"),
    Armour(6, 2, "Netherite")}; //initialising array of armour objects

    cout << "Armour Choices:" <<endl;                           //something like this implemented in the main function - link choice to character definition so they hold armour
    cout << a[0].getName()<< "(1) ";                            //we'll need pointer arrays i think if we wanna delete the objects so that no one else can use them tho lol
    cout << a[1].getName()<< "(2) ";
    cout << a[2].getName()<< "(3) "<<endl;
    cout << a[3].getName()<< "(4) ";
    cout << a[4].getName()<< "(5) ";
    cout << a[5].getName()<< "(6) " <<endl;                   //displays choices

    cout << "Pick a piece of armour by entering the number from 1-6" << endl;            //user input pick choice
    cin >> choice;

    if (choice > 0 && choice < 7 ){

        cout << "You selected this piece of armour: "<< a[choice-1].getName() << endl;

        cout << "This armour has score: " << a[choice-1].getScore() << " and type: "<< a[choice-1].getType() <<endl;          //testing funcs and making sure user input is between 1 and 6

        playerchoice=a[choice-1];
    }

    else{
        cout << "enter a valid number silly" <<endl;
        return 0;
    }

    cout << "changing type to 1" << endl;
    playerchoice.setType(1);
    cout << "your armour now has type: " << playerchoice.getType()<<endl;                                    //testing setType and getType

}