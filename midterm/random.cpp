#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 0 and 99
    int random_number = rand() % 10;

    std::cout << "Random number: " << random_number << std::endl;

    return 0;
}