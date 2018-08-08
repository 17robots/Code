#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>

class Animal {
public:
Animal(std::string name, double height, double weight, int age);
Animal(std::string name, double height, double weight);
int getAge();
double getHeight();
std::string getName();
double getWeight();

private:
    int age;
    double height, weight;
    std::string name;
};

#endif