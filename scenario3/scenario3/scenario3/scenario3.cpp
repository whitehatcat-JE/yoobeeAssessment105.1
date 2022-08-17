// Scenario 3 - Architect - Jayden Everest - 270168415
// Includes
#include <iostream>
#include <string>
// Namespaces
using std::string;
// Input error prevention
#pragma region InputHandling
// Inputs Superclass (For retrieving constrained user inputs)
class Inputs {
public:
    // Returns a user-inputted real double
    double getNum() {
        string input;
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
        double inputDouble = stod(input);
        // Checks number is within range
        if (inputDouble <= 0) {
            std::cout << "\nError: Input must be greater than 0\nPlease try again: "; 
            return getNum(); // Repeats function
        } else return inputDouble; // Returns double
    }

    // Returns a user-inputted int that matches a given range
    int getNum(int lower, int upper) {
        string input;
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
};
#pragma endregion InputHandling
// Shape calculations
#pragma region ShapeCalculators
// Shapes Superclass
class Shapes : protected Inputs {
protected:
    // Dimension Variables
    double width, height;
    // Dimension Calculations
    double calculateArea() { return width * height; }
    double calculatePerimeter() { return (width * 2) + (height * 2); }
    // Gets user input for width and height
    void getDimensions() {
        std::cout << "Enter the width (cm): ";
        width = getNum();
        std::cout << "Enter the height (cm): ";
        height = getNum();
    }
    // Math operation selection menu
    int calculationMenu(string areaOption, string perimeterOption, bool isCircle = false) {
        // Display menu
        std::cout << "\n1. Area (" << areaOption << ")\n2. " <<
            (isCircle ? "Circumference (" : "Perimeter (") << perimeterOption <<
            ")\n3. Go back to main menu\n\nPlease enter your choice (1-3): ";
        // Get user input
        return getNum(1, 3);
    }
    // Draws line of given length
    void displayLine(int length) { std::cout << string(length, '*') << std::endl; }
};
// Square child class of Shapes
class Square : private Shapes {
    // Gets user input only for width
    void getDimensions() {
        std::cout << "Enter length(cm): ";
        width = getNum();
        height = width;
    }
public:
    // Square calculation result display menu
    void menu() {
        std::cout << "\n**********\nSquare Calculator\n**********\n\n";
        for (int line = 0; line < 5; line++) { displayLine(10); } // Draw square
        switch (calculationMenu("Base^2", "Base * 4")) { // Determine which calculation to perform
            case 1: // Display area result
                getDimensions();
                std::cout << "The area is: " << calculateArea() << "sq.cm\n";
                break;
            case 2: // Display perimeter result
                getDimensions();
                std::cout << "The perimeter is: " << calculatePerimeter() << "cm\n";
                break;
            default: return; // Return to main menu
        }
        menu();
    }
};
// Rectangle child class of Shapes
class Rectangle : private Shapes {
public:
    // Rectangle calculation result display menu
    void menu() {
        std::cout << "\n**********\nRectangle Calculator\n**********\n\n";
        for (int line = 0; line < 5; line++) { displayLine(20); } // Draw rectangle
        switch (calculationMenu("Base * Height", "Base * 2 + Height * 2")) { // Determine which calculation to perform
            case 1: // Display area result
                getDimensions();
                std::cout << "The area is: " << calculateArea() << "sq.cm\n";
                break;
            case 2: // Display perimeter result
                getDimensions();
                std::cout << "The perimeter is: " << calculatePerimeter() << "cm\n";
                break;
            default: return; // Return to main menu
        }
        menu();
    }
};
// Triangle child class of Shapes
class Triangle : private Shapes {
    double calculateArea() { return (width * height) / 2; } // Calculates area of triangle
    double calculatePerimeter() { return width + sqrt(pow(width / 2, 2) + pow(height, 2)) * 2; } // Calculates perimeter of triangle
public:
    // Triangle calculation result display menu
    void menu() {
        std::cout << "\n**********\nTriangle Calculator\n**********\n\n";
        for (int line = 0; line < 5; line++) { displayLine(1+(2*line)); } // Draw triangle
        switch (calculationMenu("Base * Height / 2", "Base + Hypotenuse * 2")) { // Determine which calculation to perform
            case 1: // Display area result
                getDimensions();
                std::cout << "The area is: " << calculateArea() << "sq.cm\n";
                break;
            case 2: // Display perimeter result
                getDimensions();
                std::cout << "The perimeter is: " << calculatePerimeter() << "cm\n";
                break;
            default: return; // Return to main menu
        }
        menu();
    }
};
// Circle child class of Shapes
class Circle : private Shapes {
    // Gets user input only for radius
    void getDimensions() {
        std::cout << "Enter radius(cm): ";
        width = getNum();
        height = width;
    }
    
    double calculateArea() { return 3.14 * pow(width, 2); } // Calculates area of circle
    double calculatePerimeter() { return 2 * 3.14 * (width); } // Calculates perimeter of circle
    // Draws line of given length and offset
    void displayLine(int length, int offset) {
        std::cout << string(offset, ' ') << string(length, '*') << std::endl;
    }
public:
    // Circle calculation result display menu
    void menu() {
        std::cout << "\n**********\nCircle Calculator\n**********\n\n";
        // Pre-calculated circle dimensions
        int lineSpacing[10] = {6, 2, 2, 0, 0, 0, 0, 2, 2, 6};
        int lineLength[10] = {8, 16, 16, 20, 20, 20, 20, 16, 16, 8};
        for (int line = 0; line < 10; line++) { displayLine(lineLength[line], lineSpacing[line]); } // Draw circle
        switch (calculationMenu("Radius^2 * pi", "Radius * 2 * pi", true)) { // Determine which calculation to perform
            case 1: // Display area result
                getDimensions();
                std::cout << "The area is: " << calculateArea() << "sq.cm\n";
                break;
            case 2: // Display circumference result
                getDimensions();
                std::cout << "The circumference is: " << calculatePerimeter() << "cm\n";
                break;
            default: return; // Return to main menu
        }
        menu();
    }
};
#pragma endregion ShapeCalculators

// Main menu
int main()
{
    Inputs inputManager;
    // Shape child class initializations
    Square square;
    Rectangle rectangle;
    Triangle triangle;
    Circle circle;
    // Main menu display loop
    while (true) {
        std::cout << "**********\nShapes Calculator\n**********\n\n" << // Display options
            "1. Square\n2. Rectangle\n3. Triangle\n4. Circle\n5. Exit" << 
            "\n\nPlease enter your choice (1-5): ";
        // Get user input
        int choice = inputManager.getNum(1, 5);
        switch (choice) { // Go to corresponding shape menu
            case 1:
                square.menu();
                break;
            case 2:
                rectangle.menu();
                break;
            case 3:
                triangle.menu();
                break;
            case 4:
                circle.menu();
                break;
            default: return 0; // Exit program
        }
    }
}