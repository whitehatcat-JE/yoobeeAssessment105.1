// Scenario 3 - Architect - Jayden Everest - 270168415
// Includes
#include <iostream>
#include <string>

using std::string;


class Shapes {
    double width, height;
    public:
    double getWidth() { return width; }
    double getHeight() { return height; }

    double calculateArea() { return width * height; }
    double calculatePerimeter() { return (width * 2) + (height * 2); }

    void displayLine(int length) { std::cout << string(length, '*') << std::endl; }

    void getDimensions() {
        std::cout << "Enter the base (cm): ";
        std::cin >> width;
        std::cout << "Enter the height (cm): ";
        std::cin >> height;
    }

    void getDimensions(bool singular) {
        std::cout << "Enter length (cm): ";
        std::cin >> width;
    }

    int calculationMenu(string areaOption, string perimeterOption) {
        while (true) {
            std::cout << "\n1. Area (" << areaOption << ")\n2. Perimeter (" << perimeterOption <<
                ")\n3. Go back to main menu\n\nPlease enter your choice (1-3): ";
            int choice;
            std::cin >> choice;
            if (choice > 3 || choice < 1) std::cout << "Choice out of range. Please try again.\n";
            else return choice;
        }
    }

    void displayLine(int length, int offset) {
        std::cout << string(offset, ' ') << string(length, '*') << std::endl;
    }
};

class Square : private Shapes {
    public:
    void menu() {
        std::cout << "\n**********\nSquare Calculator\n**********\n\n";
        for (int line = 0; line < 5; line++) { displayLine(10); }
        switch (calculationMenu("Base^2", "Base * 4")) {
            case 1:
                getDimensions(true);
                std::cout << "The area is: " << calculateArea() << "sq.cm\n";
                break;
            case 2:
                getDimensions(true);
                std::cout << "The perimeter is: " << calculatePerimeter() << "cm\n";
                break;
            case 3:
                return;
        }
        menu();
    }
};

class Rectangle : private Shapes {
    public:
    void menu() {
        std::cout << "\n**********\nRectangle Calculator\n**********\n\n";
        for (int line = 0; line < 5; line++) { displayLine(20); }
        switch (calculationMenu("Base * Height", "Base * 2 + Height * 2")) {
            case 1:
                getDimensions();
                std::cout << "The area is: " << calculateArea() << "sq.cm\n";
                break;
            case 2:
                getDimensions();
                std::cout << "The perimeter is: " << calculatePerimeter() << "cm\n";
                break;
            case 3:
                return;
        }
        menu();
    }
};

class Triangle : private Shapes {
    float calculateArea(float width, float height) { return (width * height) / 2; }
    float calculatePerimeter(float width, float height) { 
        return width + height + sqrt(pow(width, 2) + pow(height, 2)); 
    }
    
    public:
    void menu() {
        std::cout << "\n**********\nTriangle Calculator\n**********\n\n";
        for (int line = 0; line < 5; line++) { displayLine(1+(2*line)); }
        switch (calculationMenu("Base * Height / 2", "Base + Height + Hypotenuse")) {
            case 1:
                getDimensions();
                std::cout << "The area is: " << calculateArea(getWidth(), getHeight()) << "sq.cm\n";
                break;
            case 2:
                getDimensions();
                std::cout << "The perimeter is: " << calculatePerimeter(getWidth(), getHeight()) << "cm\n";
                break;
            case 3:
                return;
        }
        menu();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
