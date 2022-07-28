// scenario1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Location {
    int degrees;
    float minutes;
    char direction;
    bool isLat;
public:
    Location(bool setToLat) {
        isLat = setToLat;
        degrees = 0;
        minutes = 0.0;
        direction = setToLat ? 'E' : 'N';
    }

    void setPos() {
        std::cout << "Input degrees between 0 and 180: ";
        std::cin >> degrees;

        std::cout << "Input minutes between 0 and 60: ";
        std::cin >> minutes;

        std::cout << "Input direction (" << (isLat ? "E/W): " : "N/S): ");
        std::cin >> direction;
    }

    int getDegrees() { return degrees; }

    float getMinutes() { return minutes; }

    char getDirection() { return direction; }
};

class Yacht {
    int serialNumber;
    Location* latitude;
    Location* longitude;

public:
    Yacht(int number) {
        serialNumber = number;

        latitude = new Location(true);
        longitude = new Location(false);

        latitude->setPos();
        longitude->setPos();
    }

    void display() {
        std::cout << "\n\nThe ship serial number is: " << serialNumber << "\n" <<
            "and its position is: " <<
            longitude->getDegrees() << "\xF8" << longitude->getMinutes() <<
            "' " << longitude->getDirection() << " Longitude\t" <<
            latitude->getDegrees() << "\xF8" << latitude->getMinutes() <<
            "' " << latitude->getDirection() << " Latitude";
    }
};

int main()
{
    int yachtNum = 0;
    std::cout << "**********Ocean Race 2021-22**********\n\n";
    std::cout << "**************************************\n";
    Yacht yacht1(++yachtNum);
    std::cout << "**************************************\n";
    Yacht yacht2(++yachtNum);
    std::cout << "**************************************\n";
    Yacht yacht3(++yachtNum);
    std::cout << "**********Welcome to Ocean Race 2021-22**********\n\n";

    yacht1.display();
    yacht2.display();
    yacht3.display();
}