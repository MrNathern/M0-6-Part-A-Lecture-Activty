/* Program name: M06 Programming Assignment 1
* Author: Ronald Hernandez
* Date last updated: 4/26/24
* Purpose: You are creating a program that processes custom car orders for a car dealership.
* You will create an enum that will represent colors used in the car.
* For a custom car order, the customer can pick 3 colors, the top, main body, and trim color.
*/

#include <iostream>
#include <string>
#include <iomanip> 
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <limits>
#include <fstream>


using namespace std;

//the function in order to get the color choice from the user
enum carColorType{
    SUNSET,
    CHERRY,
    PHANTOM,
    TITANIUM,
    GEAUX,
    LIGHTNING,
    FOREST,
    MIDNIGHT,
    PASSION,
    ROOT,
    STORM,
    OCEAN,
    GLACIAL
};

//the function in order to get the color choice from the user
carColorType getColor(const std::string& part) {
    int choice;
    std::cout << "Please choose a color for the " << part << endl;
    std::cout << "1. Sunset Orange" << endl;
    std::cout << "2. Cherry Bomb" << endl;
    std::cout << "3. Phantom Black" << endl;
    std::cout << "4. Titanium Silver" << endl;
    std::cout << "5. Geaux Gold" << endl;
    std::cout << "6. Lightning Yellow" << endl;
    std::cout << "7. Forest Green" << endl;
    std::cout << "8. Midnight Blue" << endl;
    std::cout << "9. Passion Purple" << endl;
    std::cout << "10. Root Beer" << endl;
    std::cout << "11. Storm Surge" << endl;
    std::cout << "12. Ocean's Rip" << endl;
    std::cout << "13. Glacial White" << endl;
    while (true){
        if (std::cin >> choice && choice >= 1 && choice <= 13){
            break;
        } else if (!std::cin){
            std::cout << "You entered something that is not a number. Please Try again." << endl;
            std::cout << "Please enter the number next to the color you want to choose: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            
            std::cout << "Please enter the number next to the color you want to choose: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return static_cast<carColorType>(choice - 1);
}

// the function to convert the color from the enum to the string
std::string printColor(carColorType color) {
    switch (color) {
        case SUNSET:
            return "Sunset Orange";
        case CHERRY:
            return "Cherry Bomb";
        case PHANTOM:
            return "Phantom Black";
        case TITANIUM:
            return "Titanium Silver";
        case GEAUX:
            return "Geaux Gold";
        case LIGHTNING:
            return "Lightning Yellow";
        case FOREST:
            return "Forest Green";
        case MIDNIGHT:
            return "Midnight Blue";
        case PASSION:
            return "Passion Purple";
        case ROOT:
            return "Root Beer";
        case STORM:
            return "Storm Surge";
        case OCEAN:
            return "Ocean's Rip";
        case GLACIAL:
            return "Glacial White";
        default:
            return "";
    }
}

int main(){
    //Welcome message
    std::cout << "Welcome to the car customizer!" << endl;

    carColorType bodyColor, topColor, trimColor;
    bodyColor = getColor("body");
    topColor = getColor("top");
    trimColor = getColor("trim");
    
    //displays what the user has chosen
    std::cout << "You have chosen " << printColor(bodyColor) << " for the body, "
              << printColor(topColor) << " for the top, and "
              << printColor(trimColor) << " for the trim." << endl;

    //gives the user the prompt to whether or not to continue
    char continueOrder;
    std::cout << "Do you want to continue with your order? ";
    std::cin >> continueOrder;
    while (true){
        if (continueOrder == 'Y' || continueOrder == 'y') {
            std::ofstream outputFile("order.txt");
            outputFile << topColor << endl;
            outputFile << bodyColor << endl;
            outputFile << trimColor << endl;
            outputFile.close();
            break;
        } else if (continueOrder == 'N' || continueOrder == 'n'){
            break;
            
        } else {
            std::cout << "Please enter Y or N." << endl;
            std::cout << "Do you want to continue with your order? ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >>continueOrder;
        }
    }
    




    return 0;
}