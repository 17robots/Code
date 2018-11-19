#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include "station.hpp"
#include "list.hpp"
#include <ctime>

//global variables for the data structure
const int NUMLABS = 8;
const int LABSIZES[NUMLABS] = {19, 15, 24, 33, 61, 17, 55, 37};
const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh", "Stanford University", "Arizona State University", "North Texas State University", "The University of Alabama, Huntsville", "Princeton University", "Duquesne University"};

// helper functions

void log(std::string message) {
    // first try to open the file
     time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    char buffer [80];
    strftime (buffer,80,"%Y-%m-%d.",now);
    std::string str(buffer);
    
    std::ofstream myfile;
    myfile.open (str + "log", std::ios_base::ate);
    if(myfile.is_open()) {
        std::cout<<"Success"<<std::endl;
    } else {
        std::cout << "Failed to open file" << std::endl;
    }
    
    strftime (buffer,80,"%d-%m-%Y %H-%M-%S",now);
    
    myfile << buffer << ": "<< message << std::endl;
    std::cout << "logged" << std::endl;
    myfile.close();
}

void intitialze(List (&list)[NUMLABS]) {
    
}

int main() {
    //variable creation
    // List universities = List[NUMLABS]; // the array to hold all of the headers of each list
    // time_t t = time(0);   // get time now
    // struct tm * now = localtime( & t );
    // char buffer [80];
    // strftime (buffer,80,"%Y-%m-%d.",now);
    
    // std::cout << buffer << "log" << std::endl;
    //initial display of everything and assignment
    return 0;
}