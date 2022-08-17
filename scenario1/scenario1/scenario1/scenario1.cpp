// Scenario 1 - Ocean Race - Jayden Everest - 270168415
// Includes
#include <iostream>
#include <string>

// Input error prevention
#pragma region InputHandling
// Inputs Superclass (For retrieving constrained user inputs)
class Inputs {
public:
    // Returns a user-inputted real float
    float getNum() {
        std::string input;
        std::cin >> input;
        // Checks something has been inputted
        if (input == "") {
            std::cout << "Alert! Nothing inputted\nPlease try again: ";
            return getNum();
        }
        // Checks input is a number
        bool decimalFound = false;
        for (int inputChar = 0; inputChar < (int) input.size(); inputChar++) {
            if ((input[inputChar] < 47 || input[inputChar] > 57) && !(input[inputChar] == '.' && !decimalFound)) {
                decimalFound = true;
                std::cout << "\nError: Input must be a number\nPlease try again: ";
                return getNum(); // Repeats function
            }
        }
        float inputDouble = stof(input);
        // Checks number is within range
        if (inputDouble < 0) {
            std::cout << "\nError: Input must be greater than or equal to 0\nPlease try again: "; 
            return getNum(); // Repeats function
        } else return inputDouble; // Returns double
    }

    // Returns a user-inputted int that matches a given range
    int getNum(int lower, int upper) {
        std::string input;
        std::cin >> input;
        // Checks something has been inputted
        if (input == "") {
            std::cout << "Alert! Nothing inputted\nPlease try again: ";
            return getNum(lower, upper);
        }
        // Checks input is a number
        for (int inputChar = 0; inputChar < (int) input.size(); inputChar++) {
            if (input[inputChar] < 47 || input[inputChar] > 57) {
                std::cout << "\nError: Input must be a number\nPlease try again: ";
                return getNum(lower, upper); // Repeats function
            }
        }
        int inputInt = stoi(input);
        // Checks number is within range
        if (inputInt < lower || inputInt > upper) {
            std::cout << "\nError: Input must be between " << lower << " and " << upper << 
                "\nPlease try again: ";
            return getNum(lower, upper); // Repeats function
        } else return inputInt; // Returns integer
    }

    // Returns a user-inputted char
    char getChar(std::string options = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") {
        std::string input;
        std::cin >> input;
        if (input.size() > 1) { // Checks only one character has been inputted
            std::cout << "\nError: Multiple characters inputted\nPlease try again: ";
            return getChar(options);
        } else if (options.find(input) == std::string::npos) { // Checks character is valid
            std::cout << "\nError: Character not recognized\nPlease try again: ";
            return getChar(options);
        } else return input[0]; // Returns character
    }
};
#pragma endregion InputHandling
// Yacht Information Storage Classes
#pragma region YachtControllers
// Yacht location class (Used in Yacht class)
class Location : private Inputs {
    // Position variables
    int degrees;
    float minutes;
    // Direction variables
    char direction;
    bool isLong;
public:
    // Location constructor
    Location(bool setToLong) {
        isLong = setToLong;
        degrees = 0;
        minutes = 0.0;
        direction = setToLong ? 'E' : 'N';
    }
    /* Sets position to user input
    NOTE: Documentation calls this "getpos", however, method is a setter, not getter, so setPos is more appropriate.
        Also, doesn't need to be repeated in Yacht class, since yacht class already can access this method through
        its location children classes.
    */
    void setPos() {
        std::cout << "Input degrees between 0 and 180: ";
        degrees = getNum(0, 180);

        std::cout << "Input minutes between 0 and 60: ";
        minutes = getNum();

        std::cout << "Input direction (" << (isLong ? "E/W): " : "N/S): ");
        direction = getChar(isLong ? "EW" : "NS");
    }
    // Position & direction getters
    int getDegrees() { return degrees; }
    float getMinutes() { return minutes; }
    char getDirection() { return direction; }
};

// Yacht information class
class Yacht {
    int serialNumber; // Identification variable
    // Position variables
    Location* latitude;
    Location* longitude;
public:
    // Yacht constructor
    Yacht(int number) {
        serialNumber = number;
        
        longitude = new Location(true);
        latitude = new Location(false);

        longitude->setPos();
        latitude->setPos();
    }
    // Displays all class information
    void display() {
        std::cout << "\n\nThe ship serial number is: " << serialNumber << "\n" <<
            "and its position is: " <<
            latitude->getDegrees() << "\xF8" << latitude->getMinutes() <<
            "' " << latitude->getDirection() << " Latitude\t" <<
            longitude->getDegrees() << "\xF8" << longitude->getMinutes() <<
            "' " << longitude->getDirection() << " Longitude";
    }
};
#pragma endregion YachtControllers

int main()
{
    // Gets 3 yachts
    int yachtNum = 0;
    std::cout << "**********Ocean Race 2021-22**********\n\n";
    std::cout << "**************************************\n" << 
        "Enter the Location of the first ship:\n";
    Yacht yacht1(++yachtNum);
    std::cout << "**************************************\n" << 
        "Enter the Location of the second ship:\n";
    Yacht yacht2(++yachtNum);
    std::cout << "**************************************\n" << 
        "Enter the Location of the third ship:\n";
    Yacht yacht3(++yachtNum);
    std::cout << "**********Welcome to Ocean Race 2021-22**********\n\n";
    // Displays yachts' information
    yacht1.display();
    yacht2.display();
    yacht3.display();
}