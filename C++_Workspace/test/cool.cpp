#include <iostream>
#include "Animal.h"

int main() {
    Animal* lion = new Animal("simba", 10.2, 135.5, 15);

    std::cout << "Name: " << lion->getName() << std::endl;
    std::cout << "Height: " << lion->getHeight() << std::endl;
    std::cout << "Weight: " << lion->getWeight() << std::endl;
    std::cout << "Age: " << lion->getAge() << std::endl;
    return 0;
}