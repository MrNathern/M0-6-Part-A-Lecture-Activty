//M06 Part A Lecture Activity
#include <iostream>
#include <fstream>
#include <limits>
#include <string>

using namespace std;

// Enum for different kinds of fish
enum class Fish {
    Tuna,
    Salmon,
    Clownfish
};

// Function to input a fish type from the user
Fish inputFish() {
    int choice;
    std::cout << "Enter the number corresponding to the type of fish: " << endl;
    std::cout << "1. Tuna " << endl;
    std::cout << "2. Salmon " << endl;
    std::cout << "3. Clownfish " << endl;
    std::cin >> choice;

    switch (choice) {
        case 1:
            return Fish::Tuna;
        case 2:
            return Fish::Salmon;
        case 3:
            return Fish::Clownfish;
        default:
            std::cerr << "Invalid choice, defaulting to Tuna. ";
            return Fish::Tuna;
    }
}

// Function to output the type of fish
void outputFish(Fish fish) {
    std::string fishName;
    switch (fish) {
        case Fish::Tuna:
            fishName = "Tuna";
            break;
        case Fish::Salmon:
            fishName = "Salmon";
            break;
        case Fish::Clownfish:
            fishName = "Clownfish";
            break;
    }
    std::cout << "You chose: " << fishName << endl;
}

int main() {
    Fish myFish;

    // Input a fish type
    myFish = inputFish();

    // Output the chosen fish type
    outputFish(myFish);

    return 0;
}

 