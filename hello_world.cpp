#include <iostream>
#include <string>

int main() {
    std::string name; // name of the user will be stored here (umm aktually this is a different comment now get rekt)
    std::cout << "Enter your name: "; // prompt the user to enter their name
    std::cin >> name; // read the name
    std::cout << "Hello world from " << name << std::endl; // print greetings to the world from the user
    return 0; // end program
}
