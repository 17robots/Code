#include <memory>
#include <iostream>

const int SIZE = 10;
int unique_char_arr_size = 1; //there will always ne at least on unique letter

std::unique_ptr<char[]> deleteRepeats(char array[SIZE]) {
    std::string unique_chars = ""; //create a string to store the unique letters in
    unique_chars += array[0];
    for(int i = 1; i < SIZE; ++i) {
        int counter = 0;
        for(int j = 0; j < unique_chars.length(); ++j) {
            if(array[i] == unique_chars.at(j)) {
                counter++; // keep track of how many times the current letter shows up in the unique character string
            }
        }

        if(counter == 0) { // if there isn't a duplicate in the unique letter string, add it to the string
            unique_chars += array[i];
            unique_char_arr_size++;
        }
    }

    std::unique_ptr<char[]> returned_ptr( new char(unique_chars.length())); // create the pointer with the string size 

    for(int i = 0; i < unique_chars.length(); ++i) {
        *(returned_ptr.get() + i) = unique_chars.at(i);
    }

    return returned_ptr;
}

void printArray(char array[]) {
    for(int i = 0; i < SIZE; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    char originalArray[SIZE];

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

    std::unique_ptr<char[]> noRepeats = deleteRepeats(originalArray);

    std::cout << "Array: ";
    printArray(originalArray);

    std::cout << "Unique Array: ";
    for(int i = 0; i < unique_char_arr_size; ++i) {
        std::cout << *(noRepeats.get() + i) << " ";
    }

    std::cout << "\nThere is a " << SIZE - unique_char_arr_size << " letter difference";

    return 0;
}