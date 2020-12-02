//
//  ra7
//
//  Created by Sydney LeBlanc on 2020-10-09.
//  Copyright © 2020 Sydney LeBlanc. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 Write a program that will allow the user to enter an integer value
 and perform the functionality specified below. You may assume that the
 entered integer will be less than or equal to 20.
 
 First, write a for loop that will allow the user to enter the specified
 number of integers one at a time. As each integer is entered,
 it is incremented by a random value less than 100 and then stored
 into an array.
 
 Second, write another for loop to print out all the array elements in
 reverse one element per line.
 
 You must a single integer array of fixed size, either as C‐style array
 or as <array>instance.
 */

void execute_ra7_q1(){
    // declare and initialize required variables
    int array_size = 0, my_array[20] = { 0 }; // intialize the array
     srand(time(0)); // set the randomization seed; include ctime if needed
    
    // step1. allow the user to specify the array size or number of entries
    cout << " Enter the intended array size: \n";
    cin >> array_size;
    
    // step2. populate the array values with the entries from the console
    for (int index = 0; index < array_size; index++) {
        int entry = 0; // individual entry
        cin >> entry;
        my_array[index] = entry + rand() % 100; // store the entry plus randomized value
    }
    
    // step3. output the array value in reverse
    for (int index = array_size - 1; index >= 0; index--) {
        cout << my_array[index] << endl;
    }
}

/*
 Write a program that will initialize an array of ten integer values as:
 int my_array[10] = {...}. The code will then sort and output the array
 values in ascending (non‐descending if there are duplicates) order.
 
 Use one Boolean variable to record if the array is sorted and another
 Boolean to record if swaps are made. Create a single swap function
 that takes two integer reference as input and performs the swap.
 */

//PURPOSE: performs bubble sort to sort a given array in ascending order
void execute_ra7_q2(){
    //declare and initialize variables
    bool is_sorted = false;
    int unsorted_data[10] = { 14, 12, 5, 7, 7, 1, 2, 4, 42, 5 };
    //step1. apply Bubble Sort to sort the array values
    while (!is_sorted) { //step1.1 keep going while the array is still unsorted
        bool swap_performed = false;
        //step1.1.1 keep checking if there is a pair that is out of order
            
        for (int index = 0; index < 9; index++) {
            //step1.1.2 perform the swap if a pair os out of order
            if (unsorted_data[index] > unsorted_data[index + 1]) {
                int temp = unsorted_data[index]; // swap the two adjacent values
                unsorted_data[index] = unsorted_data[index + 1];
                unsorted_data[index + 1] = temp;
                swap_performed = true;
            }
        }
        //step1.2 check if the array is sorted based on number of swaps performed
        is_sorted = !swap_performed;
    }
    //step2. output sorted array results
    for (int index = 0; index < 10; index++) {
        cout << unsorted_data[index] << endl;
    }
}

int main() {
    execute_ra7_q1();
    execute_ra7_q2();
}
