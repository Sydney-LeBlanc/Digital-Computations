//
//  ra8
//
//  Created by Sydney LeBlanc on 2020-10-21.
//  Copyright © 2020 Sydney LeBlanc. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

// OVERALL OBJECTIVE: write a search function where a given key value
// is verified for its existence in a given data structure (e.g., array)

bool check_if_exists(int my_array[] /* basic array*/,
                        int array_size,
                        int key_value);
// PURPOSE: checks if the given key value already exists in the given array
//     INPUTS: my_array - the array of given values
//               array_size - the size of the given array
//               key_value - the given key value to be checked
//       OUTPUTS: true if the value is found inside the array; false otherwise

void generate_values(int my_array[], int array_size);
//PURPOSE:generates aspecified number of unique integer values
//and stores them into an array
//INPUTS: my_array ‐ array that will contain the generated values
//array_size ‐ size of the array
//OUTPUTS:values returned by reference

void output_values(int my_array[], int array_size);
//PURPOSE: outputs all the generated values
//INPUTS: my_array ‐ array that contains the generated values
//array_size ‐ size of the array
//OUTPUTS: output to the console

bool check_if_exists(int my_array[], int array_size, int value) {
    // step0. declare and initialize required variables
    bool is_present = false;

    // illustration: {1 [0], 7 [1], 15 [2], 2 [3], 42 [4], 17, ...}
    //                    and key = 42

    // step1. iterate through the array and determine
    //        if the key value exists in that array
    for (int index = 0; index < array_size && !is_present; index++) {
        // step1.1. check if the current index value is 42
        if (my_array[index] == value) // == means compare the two values
            is_present = true; // update the boolean return value

        // DO NOT INSERT THE FOLLOWING: shown as additional explanation
        // else
        //     is_present = false; // INCONSISTENT: overwrites
                                // that we may have already found the value
    }
    // step2. output the resulting boolean value
    return is_present;
}

void generate_values(int my_array[], int array_size){
    int index = 0;
    bool it_exists;
    
    while(index < array_size) {
        
        it_exists = true;
        
        while (it_exists) {
            int value = rand() % array_size + 1;
            
            it_exists = check_if_exists(my_array, array_size, value);
            
            if (!it_exists) {
                my_array[index] = value;
                ++index;
            }
        }
    }
}

void output_values(int my_array[], int array_size){
    for (int index = 0; index < array_size; ++index) {
         cout << setw(2) << setfill('0') << my_array[index] << "\n";
    }
}

int main() {
    // [setup]declareandinitializevariables
    const int MAX_SIZE = 15;
    int my_array[MAX_SIZE] = {0};
    //[INPUT]settherandomizationseed
    srand(static_cast<unsigned int>(time(0)));
    //[PROCESSING]generate unique values
    generate_values(my_array,MAX_SIZE);
    //[OUTPUT]output the generated values
    output_values(my_array,MAX_SIZE);
}
