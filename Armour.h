#ifndef ARMOUR_H
#define ARMOUR_H
#include <string>


class Armour
{

private:
    int score;
    int type;
    std::string name;

public:
    Armour();
    Armour(int armScore, int armType, std::string armName);              //armour has an integer score, type(heavy/light) and material (iron diamond gold etc)

    int getScore();
    int getType();
    std::string getName();

    void setName(std::string armName);
    void setScore(int armScore);
    void setType(int armType);

    ~Armour();

};

#endif