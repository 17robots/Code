#include "Animal.h"

Animal::Animal(std::string Name, double Height, double Weight, int Age) {
    name = Name;
    height = Height;
    weight = Weight;
    age = Age;
}

Animal::Animal(std::string Name, double Height, double Weight) {
    name = Name;
    height = Height;
    weight = weight;
    age = 0;
}

int Animal::getAge() {
    return age;
}

double Animal::getHeight() {
    return height;
}

std::string Animal::getName() {
    return name;
}

double Animal::getWeight() {
    return weight;
}