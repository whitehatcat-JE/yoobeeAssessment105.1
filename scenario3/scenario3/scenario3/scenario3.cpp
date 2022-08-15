// Scenario 3 - Architect - Jayden Everest - 270168415
// Includes
#include <iostream>
#include <string>
// Namespaces
using std::string;

// Shapes Superclass
class Shapes {
    protected:
    // Dimension Variables
    double width, height;
    // Dimension Calculations
    double calculateArea() { return width * height; }
    double calculatePerimeter() { return (width * 2) + (height * 2); }
    // Gets user input for width and height
    void getDimensions() {
        std::cout << "Enter the width (cm): ";
        std::cin >> width;
        std::cout << "Enter the height (cm): ";
        std::cin >> height;
    }
    // Math operation selection menu
    int calculationMenu(string areaOption, string perimeterOption, bool isCircle = false) {
        while (true) { // Loop until valid input is given
            // Display menu
            std::cout << "\n1. Area (" << areaOption << ")\n2. " <<
                (isCircle ? "Circumference (" : "Perimeter (") << perimeterOption <<
                ")\n3. Go back to main menu\n\nPlease enter your choice (1-3): ";
            // Get user input
            int choice;
            std::cin >> choice;
            if (choice > 3 || choice < 1) std::cout << "Choice out of range. Please try again.\n";
            else return choice;
        }
    }
    // Draws line of given length
    void displayLine(int length) { std::cout << string(length, '*') << std::endl; }
    // Draws line of given length and offset
    void displayLine(int length, int offset) {
        std::cout << string(offset, ' ') << string(length, '*') << std::endl;
    }
};

// Square child class of Shapes
class Square : private Shapes {
    // Gets user input only for width
    void getDimensions() {
        std::cout << "Enter length(cm): ";
        std::cin >> width;
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
            case 3: // Return to main menu
                return;
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
            case 3: // Return to main menu
                return;
        }
        menu();
    }
};

// Triangle child class of Shapes
class Triangle : private Shapes {
    float calculateArea() { return (width * height) / 2; } // Calculates area of triangle
    float calculatePerimeter() { // Calculates perimeter of triangle
        return width + sqrt(pow(width / 2, 2) + pow(height, 2)) * 2; 
    }
    
    public:
    // Triangle calculation result display menu
    void menu() {
        std::cout << "\n**********\nTriangle Calculator\n**********\n\n";
        for (int line = 0; line < 5; line++) { displayLine(1+(2*line)); } // Draw triangle
        switch (calculationMenu("Base * Height / 2", "Base + Height + Hypotenuse")) { // Determine which calculation to perform
            case 1: // Display area result
                getDimensions();
                std::cout << "The area is: " << calculateArea() << "sq.cm\n";
                break;
            case 2: // Display perimeter result
                getDimensions();
                std::cout << "The perimeter is: " << calculatePerimeter() << "cm\n";
                break;
            case 3: // Return to main menu
                return;
        }
        menu();
    }
};

// Circle child class of Shapes
class Circle : private Shapes {
    // Gets user input only for radius
    void getDimensions() {
        std::cout << "Enter radius(cm): ";
        std::cin >> width;
        height = width;
    }
    
    float calculateArea() { return 3.14 * pow(width, 2); } // Calculates area of circle
    float calculatePerimeter() { return 2 * 3.14 * (width); } // Calculates perimeter of circle
    
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
            case 3: // Return to main menu
                return;
        }
        menu();
    }
};

// Main menu
int main()
{
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
        int choice;
        std::cin >> choice;
        if (choice > 5 || choice < 1) std::cout << "Choice out of range. Please try again.\n";
        else {
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
                case 5: // Exit program
                    return 0;
            }
        }
    }
}