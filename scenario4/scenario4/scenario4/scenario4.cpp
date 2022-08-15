// scenario4.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>

using std::vector;

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

    void operator =(Alien alienB) {
        weight = alienB.getWeight();
        height = alienB.getHeight();
        gender = alienB.getGender();
    }

    Alien operator +(Alien alienB) {
        int startingWeight = (weight + alienB.getWeight()) / 2;
        int startingHeight = (height + alienB.getHeight()) / 2;
        char startingGender = rand() % 2 == 0 ? 'm' : 'f';
        Alien child(startingWeight, startingHeight, startingGender);
        return child;
    }
};

int main()
{
    vector<Alien*> aliens;
    Alien* childA = NULL;
    Alien* childB = NULL;
    while (true) {
        std::cout << "Main Menu: \n" <<
            "1. Create Alien Pairs.\n" <<
            "2. Create offsprings.\n" <<
            "3. Compare offspring prestige.\n" <<
            "4. Exit\n: ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                for (int existingAlien = 0; existingAlien < aliens.size(); existingAlien++) {
                    delete aliens[existingAlien];
                }
                aliens.clear();
                if (childA == NULL) { delete childA; };
                if (childB == NULL) { delete childB; };
                childA = NULL;
                childB = NULL;
                aliens.push_back(new Alien(rand() % 10, rand() % 10, 'm'));
                aliens.push_back(new Alien(rand() % 10, rand() % 10, 'm'));
                aliens.push_back(new Alien(rand() % 10, rand() % 10, 'f'));
                aliens.push_back(new Alien(rand() % 10, rand() % 10, 'f'));
                break;
            case 2:
                if (aliens.size() == 0) {
                    std::cout << "No Aliens have been created!\n";
                    break;
                } else {
                    if (childA == NULL) { delete childA; };
                    if (childB == NULL) { delete childB; };
                    childA = &(*aliens[0] + *aliens[1]);
                    childB = &(*aliens[2] + *aliens[3]);
                }
        }
    }
}