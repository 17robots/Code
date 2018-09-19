// NAME: Matthew Dray
// FILENAME: deleteRepeat.cpp
// PURPOSE: To delete the repeating characters from a string

#include <memory>
#include <iostream>

const int SIZE = 10;
int UNIQUE_CHAR_ARR_SIZE = 1; //there will always be at least on unique letter
//Precondition: the array is made off characters and the array is initialized
//with the SIZE veriable 
//Postcondition: returns a unique pointer to the unique character array on the
//heap
std::unique_ptr<char[]> deleteRepeats(char array[SIZE]) {
	std::string unique_chars = ""; // string to store the unique letters in
    unique_chars += array[0]; // the first character in the array is always unique
	
    for(int i = 1; i < SIZE; ++i) {
        int counter = 0; // counts how many times the character appears in the unique character string
        for(int j = 0; j < unique_chars.length(); ++j) {
            if(array[i] == unique_chars.at(j)) {
                counter++;
            }
        }

        if(counter == 0) { // if there isn't a duplicate in the unique letter string, add it to the string
            unique_chars += array[i];
            UNIQUE_CHAR_ARR_SIZE++;
        }
    }

    std::unique_ptr<char[]> returned_ptr( new char(unique_chars.length())); // create the pointer with the string size to return 

    for(int i = 0; i < unique_chars.length(); ++i) {
        *(returned_ptr.get() + i) = unique_chars.at(i);
    }

    return returned_ptr;
}

int main() {
    char originalArray[SIZE]; // the character array

	// filling the array
    originalArray [0] = 'a';
    originalArray [1] = 'b';
    originalArray [2] = 'b';
    originalArray [3] = 'c';
    originalArray [4] = 'a';
    originalArray [5] = 'c';
    originalArray [6] = 'a';
    originalArray [7] = 'c';
    originalArray [8] = 'b';
    originalArray [9] = 'c';

    std::unique_ptr<char[]> noRepeats = deleteRepeats(originalArray); //the pointer for the array on the heap that stores the unique characters

	// printing everything out
    std::cout << "Original Array: ";
    for(int i = 0; i < SIZE; ++i) {
        std::cout << originalArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Unique Array: ";
    for(int i = 0; i < UNIQUE_CHAR_ARR_SIZE; ++i) {
        std::cout << *(noRepeats.get() + i) << " ";
    }

    std::cout << "\nThere is a " << SIZE - UNIQUE_CHAR_ARR_SIZE << " letter difference";
    return 0;
}

