#include <iostream>
#include "string"
#include "Armour.h"

using namespace std;

Armour::Armour(){

    score=0;
    type=0;                                                                 //someone do an if type is 1 output string light and if type 2 output heavy for the UI
    name='?';

}

Armour::Armour(int armScore, int armType, std::string armName){
    score=armScore;                                                        //1 = light, 2 = heavy
    name=armName;
    type=armType;
}

int Armour::getScore(){                                         //each armour material has an associated score, this score is one of the variables in total character score including wep damage and the same type multiplier buff.
    return score;
}

int Armour::getType(){                       //type is heavy/light and categorises the 6 materials into 2 groups-> If type=heavy, material=netherite, diamond or iron. If type=light, material=leather, chain or gold.
   return type;
}

std::string Armour::getName(){
    return name;
}

void Armour::setName(std::string armName){
   this->name=armName;
}

void Armour::setScore(int armScore){
    this->score=armScore;
}

void Armour::setType(int armType){
    if (armType==1 || armType==2){
        this->type=armType;
    }
    else{
        cout << "type setting error, must be 1 or 2" << endl;
        return;
    }
}

Armour::~Armour(){

}
