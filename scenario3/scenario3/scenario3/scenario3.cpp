// Scenario 3 - Architect - Jayden Everest - 270168415
// Includes
#include <iostream>

class Shapes {
    public:
    float calculateArea(float width, float height) { return width * height; }

    float calculatePerimeter(float width, float height) { return (width * 2) + (height * 2); }
};

class Square : private Shapes {
    public:
    void menu() {
        std::cout << "\n**********\nSquare Calculator\n**********\n\n" <<
            "**********\n" <<
            "**********\n" <<
            "**********\n" <<
            "**********\n" <<
            "**********\n\n" <<
            "1. Area (Base^2)\n" <<
            "2. Perimeter (Base * 4)\n" <<
            "3. Go back to main menu (Shapes calculator)\n" <<
            "\nPlease enter your choice (1-3): ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter the base (cm): ";
                float base;
                std::cin >> base;
                std::cout << "The area is: " << calculateArea(base, base) << "sq.cm\n";
                break;
            case 2:
                std::cout << "Enter the base (cm): ";
                float base;
                std::cin >> base;
                std::cout << "The perimeter is: " << calculatePerimeter(base, base) << "cm\n";
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice\n";
                break;
        }
        menu();
    }
};

class Rectange : private Shapes {
    public:
    void menu() {
        std::cout << "\n**********\nRectangle Calculator\n**********\n\n" <<
            "******************************\n" <<
            "******************************\n" <<
            "******************************\n" <<
            "******************************\n" <<
            "******************************\n\n" <<
            "1. Area (Base * Height)\n" <<
            "2. Perimeter (Base * 2 + Height * 2)\n" <<
            "3. Go back to main menu (Shapes calculator)\n" <<
            "\nPlease enter your choice (1-3): ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter the base (cm): ";
                float base;
                std::cin >> base;
                std::cout << "Enter the height (cm): ";
                float height;
                std::cin >> height;
                std::cout << "The area is: " << calculateArea(base, height) << "sq.cm\n";
                break;
            case 2:
                std::cout << "Enter the base (cm): ";
                float base;
                std::cin >> base;
                std::cout << "Enter the height (cm): ";
                float height;
                std::cin >> height;
                std::cout << "The perimeter is: " << calculatePerimeter(base, height) << "cm\n";
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice\n";
                break;
        }
        menu();
    }
};

class Triangle : private Shapes {
    float calculateArea(float base, float height) { return (base * height) / 2; }
    float calculatePerimeter(float base, float height) { return base + height + sqrt(pow(base, 2) + pow(height, 2)); }
    
    public:
    void menu() {
        std::cout << "\n**********\nTriangle Calculator\n**********\n\n" <<
            "*\n" <<
            "***\n" <<
            "*****\n" <<
            "*******\n" <<
            "*********\n" <<
            "***********\n\n" <<
            "1. Area (Base * Height / 2)\n" <<
            "2. Perimeter (Base + Height + Hypotenuse)\n" <<
            "3. Go back to main menu (Shapes calculator)\n" <<
            "\nPlease enter your choice (1-3): ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter the base (cm): ";
                float base;
                std::cin >> base;
                std::cout << "Enter the height (cm): ";
                float height;
                std::cin >> height;
                std::cout << "The area is: " << calculateArea(base, height) << "sq.cm\n";
                break;
            case 2:
                std::cout << "Enter the base (cm): ";
                float base;
                std::cin >> base;
                std::cout << "Enter the height (cm): ";
                float height;
                std::cin >> height;
                std::cout << "The perimeter is: " << calculatePerimeter(base, height) << "cm\n";
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice\n";
                break;
        }
        menu();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
