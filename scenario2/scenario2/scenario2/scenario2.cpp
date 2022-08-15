// Scenario 2 - RPG - Jayden Everest - 270168415
// Includes
#include <iostream>
#include <string>
#include <vector>
// Using namespaces
using std::string;
using std::vector;
// Race enum
enum class Species {
    HUMAN,
    ELF,
    DWARF,
    ORC,
    TROLL
};

// Player class
class Player {
    // Player information variables
    string name;
    Species race;
    int hitPoints;
    int magicPoints;
public:
    // Class constructor
    Player(string plrName, Species plrRace, int hitAmt, int magicAmt) {
        name = plrName;
        race = plrRace;
        hitPoints = hitAmt;
        magicPoints = magicAmt;
    }
    // Name getter
    string getName() { return name; }
    // Race getter
    Species getRace() { return race; }
    // Converts race into string and returns it
    string whatRace() {
        switch (race) { // Note: Return breaks out of switch, so breaks not needed
        case Species::HUMAN:
            return "human";
        case Species::ELF:
            return "elf";
        case Species::DWARF:
            return "dwarf";
        case Species::ORC:
            return "orc";
        case Species::TROLL:
            return "troll";
        default:
            return "unknown";
        }
    }
    // Hit points getter
    int getHitPoints() { return hitPoints; }
    // Magic points getter
    int getMagicPoints() { return magicPoints; }
    // Name setter
    void setName(string newName) { name = newName; }
    // Race setter
    void setRace(Species newRace) { race = newRace; }
    // Hit points setter
    void setHitPoints(int newHitPoints) { hitPoints = newHitPoints; }
    // Magic points setter
    void setMagicPoints(int newMagicPoints) { magicPoints = newMagicPoints; }
    // Attack method
    string attack() { return "No attack method defined yet!"; }
};

// Warrior specialization class
class Warrior : public Player {
public:
    Warrior(string plrName, Species plrRace, int hitAmt, int magicAmt) : Player(plrName, plrRace, hitAmt, magicAmt) {}
    string attack() { return "I will destroy you with my sword!"; }
};

// Priest specialization class
class Priest : public Player {
public:
    Priest(string plrName, Species plrRace, int hitAmt, int magicAmt) : Player(plrName, plrRace, hitAmt, magicAmt) {}
    string attack() { return "I will assault you eith holy wrath!"; }
};

// Mage specialization class
class Mage : public Player {
public:
    Mage(string plrName, Species plrRace, int hitAmt, int magicAmt) : Player(plrName, plrRace, hitAmt, magicAmt) {}
    string attack() { return "I will crush you with my arcane missiles!"; }
};

// Returns a user-inputted int that matches a given range
int getInt(int lowerLimit = 1, int upperLimit = 100000) {
    string input;
    std::cin >> input;
    // Checks something has been inputted
    if (input == "") {
        std::cout << "Alert! Nothing inputted, please try again: ";
        return getInt(lowerLimit, upperLimit);
    }
    // Checks input is a number
    for (int inputChar = 0; inputChar < input.size(); inputChar++) {
        if (input[inputChar] < 47 || input[inputChar] > 57) {
            std::cout << "\nError: Input must be a number\nPlease try again: ";
            return getInt(lowerLimit, upperLimit); // Repeats function
        }
    }
    int inputInt = stoi(input);
    // Checks number is within range
    if (inputInt < lowerLimit) { // Lower limit
        std::cout << "\nError: Input must be greater or equal to " << lowerLimit << "\nPlease try again: ";
        return getInt(lowerLimit, upperLimit); // Repeats function
    }
    else if (inputInt > upperLimit) { // Upper limit
        std::cout << "\nError: Input must be less than or equal to " << upperLimit << "\nPlease try again: ";
        return getInt(lowerLimit, upperLimit); // Repeats function
    }
    // Returns integer
    return inputInt;
}

// Returns a string with spaces
string getSpaced() {
    string input = "";
    if (std::cin.peek() != '\n') std::cin.putback('\n'); // Stops first char from being omitted during cin
    std::cin.ignore();
    getline(std::cin, input);
    // Checks something has been inputted
    if (input == "") {
        std::cout << "Alert! Nothing inputted, please try again:\n";
        return getSpaced();
    }
    return input;
}

int main()
{
    // Players storage
    vector<Warrior*> warriors;
    vector<Priest*> priests;
    vector<Mage*> mages;

    // Create players
    while (true) {
        // Class selection
        std::cout << "\n\tCHARACTER CREATOR" << 
            "\nWhich of the following would you like?\n" <<
            "\t1. Create a Warrior!\n" <<
            "\t2. Create a Priest!\n" <<
            "\t3. Create a Mage!\n" <<
            "\t4. Finish creating player characters!\n: ";
        int classChoice = getInt(1, 4);
        if (classChoice == 4) { break; }
        // Race selection
        std::cout << "Which race do you want?\n" <<
            "\t1. Human!\n" <<
            "\t2. Elf!\n" <<
            "\t3. Dwarf!\n" <<
            "\t4. Orc!\n" <<
            "\t5. Troll!\n: ";
        int race = getInt(1, 5);
        // Name selection
        std::cout << "What would you like to name your character? ";
        string name = getSpaced();
        // Stores player in vector based on class selection
        switch (classChoice)
        {
            case 1:
                warriors.push_back(new Warrior(name, Species(race-1), 200, 0));
                break;
            case 2:
                priests.push_back(new Priest(name, Species(race-1), 100, 200));
                break;
            case 3:
                mages.push_back(new Mage(name, Species(race-1), 200, 0));
                break;
            default:
                std::cout << "Unknown class selected!";
                break;
        }
    }

    // Display all players
    // Warrior printout
    for (int plr = 0; plr < warriors.size(); plr++) {
        if (plr == 0) { std::cout << "\n----------------\nWARRIORS LIST:\n----------------\n"; };
        std::cout << "I am a warrior with name " << warriors[plr]->getName() <<
            " and with race " << warriors[plr]->whatRace() <<
            " and my attack is : " << warriors[plr]->attack() << std::endl;
        // Frees Warrior from stack
        delete warriors[plr];
    }
    // Priest printout
    for (int plr = 0; plr < priests.size(); plr++) {
        if (plr == 0) { std::cout << "\n----------------\nPRIESTS LIST:\n----------------\n"; };
        std::cout << "I am a priest with name " << priests[plr]->getName() <<
            " and with race " << priests[plr]->whatRace() <<
            " and my attack is : " << priests[plr]->attack() << std::endl;
        // Frees Priest from stack
        delete priests[plr];
    }
    // Mage printout
    for (int plr = 0; plr < mages.size(); plr++) {
        if (plr == 0) { std::cout << "\n----------------\nMAGES LIST:\n----------------\n"; };
        std::cout << "I am a mage with name " << mages[plr]->getName() <<
            " and with race " << mages[plr]->whatRace() <<
            " and my attack is : " << mages[plr]->attack() << std::endl;
        // Frees Mage from stack
        delete mages[plr];
    }
}