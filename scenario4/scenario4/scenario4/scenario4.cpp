// scenario4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Alien {
    int weight;
    int height;
    char gender;


    int getWeight() { return weight; }
    int getHeight() { return height; }
    char getGender() { return gender; }

    public:
    Alien(int birthWeight, int birthHeight, char birthGender) {
        weight = birthWeight;
        height = birthHeight;
        gender = birthGender;
    }
    int getPrestige() { return height * weight * (gender == 'm' ? 2 : 3); }

    bool operator ==(Alien alienB) { return getPrestige() == alienB.getPrestige(); }
    bool operator !=(Alien alienB) { return getPrestige() != alienB.getPrestige(); }
    bool operator >(Alien alienB) { return getPrestige() > alienB.getPrestige(); }
    bool operator <(Alien alienB) { return getPrestige() < alienB.getPrestige(); }
    bool operator >=(Alien alienB) { return getPrestige() >= alienB.getPrestige(); }
    bool operator <=(Alien alienB) { return getPrestige() <= alienB.getPrestige(); }
};

int main()
{
    
}