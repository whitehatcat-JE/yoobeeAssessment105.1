// Scenario 4  - Alien - Jayden Everest - 270168415
// Includes
#include <iostream>
#include <vector>
#include <string>
// Using namespaces
using std::vector;
// Individual Alien Class (Manages 1 alien instance)
class Alien {
    // Biological information
    int weight;
    int height;
    char gender;
    // Biological information getters
    int getWeight() { return weight; }
    int getHeight() { return height; }
    char getGender() { return gender; }
public:
    Alien() { reset(); } // Default constructor (Marks class instance as a placeholder)
    Alien(int birthWeight, int birthHeight, char birthGender) { // Constructor for non-placeholder alien instance
        weight = birthWeight;
        height = birthHeight;
        gender = birthGender;
    }
    // Reset function (Resets alien instance to placeholder)
    void reset() { weight = 0; }
    bool isSet() {return weight != 0;} // Returns true if alien instance is not a placeholder
    // Calculates & returns prestige of alien instance
    int getPrestige() { return height * weight * (gender == 'm' ? 2 : 3); }
    // Operator overloads for comparing aliens
    bool operator ==(Alien alienB) { return getPrestige() == alienB.getPrestige(); } // ==
    bool operator !=(Alien alienB) { return getPrestige() != alienB.getPrestige(); } // !=
    bool operator >(Alien alienB) { return getPrestige() > alienB.getPrestige(); } // >
    bool operator <(Alien alienB) { return getPrestige() < alienB.getPrestige(); } // <
    bool operator >=(Alien alienB) { return getPrestige() >= alienB.getPrestige(); } // >=
    bool operator <=(Alien alienB) { return getPrestige() <= alienB.getPrestige(); } // <=
    void operator =(Alien alienB) { // Overrides this alien instance's biological information with another instance's
        weight = alienB.getWeight();
        height = alienB.getHeight();
        gender = alienB.getGender();
    }
    // Creates a child instance, merging this alien instance's biological information with another instance's
    Alien operator +(Alien alienB) {
        // Sets child weight/height to averages of parent instances
        int startingWeight = (weight + alienB.getWeight()) / 2;
        int startingHeight = (height + alienB.getHeight()) / 2;
        char startingGender = rand() % 2 == 0 ? 'm' : 'f'; // Randomly chooses child gender
        Alien child(startingWeight, startingHeight, startingGender); // Creates child instance
        return child; // Returns child instance
    }
};

// Returns a user-inputted int that matches a given range
int getInt(int lower = 1, int upper = 100000) {
    std::string input;
    std::cin >> input;
    // Checks something has been inputted
    if (input == "") {
        std::cout << "Alert! Nothing inputted\nPlease try again: ";
        return getInt(lower, upper);
    }
    // Checks input is a number
    for (int inputChar = 0; inputChar < input.size(); inputChar++) {
        if (input[inputChar] < 47 || input[inputChar] > 57) {
            std::cout << "\nError: Input must be a number\nPlease try again: ";
            return getInt(lower, upper); // Repeats function
        }
    }
    int inputInt = stoi(input);
    // Checks number is within range
    if (inputInt < lower || inputInt > upper) {
        std::cout << "\nError: Input must be between " << lower << " and " << upper << 
            "\nPlease try again: ";
        return getInt(lower, upper); // Repeats function
    } else return inputInt; // Returns integer
}

int main()
{
    vector<Alien*> aliens; // Alien pairs vector
    // Alien children instances
    Alien childA;
    Alien childB;
    // Main menu loop
    while (true) {
        std::cout << "Main Menu: \n" << // Displays menu options
            "1. Create Alien Pairs.\n" <<
            "2. Create offsprings.\n" <<
            "3. Compare offspring prestige.\n" <<
            "4. Exit\n: ";
        int choice = getInt(1, 4); // Gets user menu choice
        // Executes selected menu option
        switch (choice) {
            case 1: // Creates parent aliens
                // Deletes current aliens
                for (int alien = 0; alien < (int) aliens.size(); alien++) delete aliens[alien];
                aliens.clear();
                childA.reset();
                childB.reset();
                // Creates new parent aliens
                aliens.push_back(new Alien((rand() % 10) + 1, (rand() % 10) + 1, 'm'));
                aliens.push_back(new Alien((rand() % 10) + 1, (rand() % 10) + 1, 'm'));
                aliens.push_back(new Alien((rand() % 10) + 1, (rand() % 10) + 1, 'f'));
                aliens.push_back(new Alien((rand() % 10) + 1, (rand() % 10) + 1, 'f'));
                std::cout << "Pairs created.\n\n"; // Displays completion message
                break;
            case 2: // Creates offspring
                if (aliens.size() == 0) std::cout << "Alien pairs must be created first!\n\n";
                else {
                    childA = *aliens[0] + *aliens[1];
                    childB = *aliens[2] + *aliens[3];
                    std::cout << "Offsprings created... Alien5 and Alien6\n\n";
                } break;
            case 3: // Compares offspring prestige
                if (!childA.isSet()) std::cout << "Offsprings must be created first!\n\n";
                else {
                    std::cout << "Offspring Prestige Comparision\n" << // Comparision chart
                        "Alien5 == Alien6 ? " << ((childA == childB) ? "true" : "false") << "\n" <<
                        "Alien5 != Alien6 ? " << ((childA != childB) ? "true" : "false") << "\n" <<
                        "Alien5 > Alien6 ? " << ((childA > childB) ? "true" : "false") << "\n" <<
                        "Alien5 >= Alien6 ? " << ((childA >= childB) ? "true" : "false") << "\n" <<
                        "Alien5 < Alien6 ? " << ((childA < childB) ? "true" : "false") << "\n" <<
                        "Alien5 <= Alien6 ? " << ((childA <= childB) ? "true" : "false") << "\n\n";
                } break;
            default: return 0;
        }
    }
}