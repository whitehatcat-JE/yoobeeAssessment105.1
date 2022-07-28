// Scenario 2 - RPG - Jayden Everest - 270168415
// Includes
#include <iostream>
#include <string>
#include <vector>
// Using namespaces
using std::string;
using std::vector;
// Race enum
enum Species {
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
    int abilityClass;
    int hitPoints;
    int magicPoints;
public:
    // Class constructor
    Player(string plrName, Species plrRace, int hitAmt, int magicAmt, int ability) {
        name = plrName;
        race = plrRace;
        hitPoints = hitAmt;
        magicPoints = magicAmt;
        abilityClass = ability;
    }
    // Name getter
    string getName() {
        return name;
    }
    // Race getter
    Species getRace() {
        return race;
    }
    // Converts race into string and returns it
    string whatRace() {
        switch (race)
        {
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
    int getHitPoints() {
        return hitPoints;
    }
    // Magic points getter
    int getMagicPoints() {
        return magicPoints;
    }
    // Name setter
    void setName(string newName) {
        name = newName;
    }
    // Race setter
    void setRace(Species newRace) {
        race = newRace;
    }
    // Hit points setter
    void setHitPoints(int newHitPoints) {
        hitPoints = newHitPoints;
    }
    // Magic points setter
    void setMagicPoints(int newMagicPoints) {
        magicPoints = newMagicPoints;
    }
    // Attack method
    string attack() {
        switch (abilityClass) {
        case 1:
            return "I will destroy you with my sword!";
        case 2:
            return "I will assault you with holy wrath!";
        case 3:
            return "I will crush you with my arcane missiles!";
        default:
            return "No attack method defined yet!";
        }
    }
};

int main()
{
    // Players storage
    vector<Player*> warriors;
    vector<Player*> priests;
    vector<Player*> mages;

    // Create players
    while (true) {
        // Class selection
        std::cout << "\n\tCHARACTER CREATOR" << 
            "\nWhich of the following would you like?\n" <<
            "\t1. Create a Warrior!\n" <<
            "\t2. Create a Priest!\n" <<
            "\t3. Create a Mage!\n" <<
            "\t4. Finish creating player characters!\n";
        int choice;
        std::cin >> choice;
        if (choice == 4) {
            break;
        }
        // Race selection
        std::cout << "Which race do you want?\n" <<
            "\t1. Human!\n" <<
            "\t2. Elf!\n" <<
            "\t3. Dwarf!\n" <<
            "\t4. Orc!\n" <<
            "\t5. Troll!\n";
        int race;
        std::cin >> race;
        // Name selection
        string name;
        std::cout << "What would you like to name your character? ";
        std::cin >> name;
        // Stores player in vector based on class selection
        switch (choice)
        {
            case 1:
                warriors.push_back(new Player(name, Species(race-1), 200, 0, 1));
                break;
            case 2:
                priests.push_back(new Player(name, Species(race-1), 100, 200, 2));
                break;
            case 3:
                mages.push_back(new Player(name, Species(race-1), 200, 0, 3));
                break;
            default:
                std::cout << "Unknown class selected!";
                break;
        }
    }

    // Display all players
    // Warrior printout
    std::cout << "\n----------------\nWARRIORS LIST:\n----------------\n";
    for (int i = 0; i < warriors.size(); i++) {
        std::cout << "I am a warrior with name " << warriors[i]->getName() <<
            " and with race " << warriors[i]->whatRace() <<
            " and my attack is : " << warriors[i]->attack() << std::endl;
    }
    // Priest printout
    std::cout << "\n----------------\nPRIESTS LIST:\n-----------------\n";
    for (int i = 0; i < priests.size(); i++) {
        std::cout << "I am a priest with name " << priests[i]->getName() <<
            " and with race " << priests[i]->whatRace() <<
            " and my attack is : " << priests[i]->attack() << std::endl;
    }
    // Mage printout
    std::cout << "\n----------------\nMAGES LIST:\n----------------\n";
    for (int i = 0; i < mages.size(); i++) {
        std::cout << "I am a mage with name " << mages[i]->getName() <<
            " and with race " << mages[i]->whatRace() <<
            "and my attack is : " << mages[i]->attack() << std::endl;
    }
}