//
//  mean_max_min.cpp
//
//  Created by Sydney LeBlanc on 2020-10-01.
//  Copyright © 2020 Sydney LeBlanc. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 Write a program that will allow the user to enter an integer greater than zero. The program will then ask
the user to enter specified amount of double values one at a time.

After the final value has been entered, the program will then compute and
output minimum, maximum, and average values.

Follow the Input‐Processing‐Output approach and leave minimal code inside the main() function. You
must include one function for input, one or more functions for processing, and one function for output.

Do not use arrays.
*/

void set_entry_count(int& entry_count);
//PURPOSE: Allows the user to set the entry count
//    INPUTS: entry_count - integer value reference that will contain the inputted entry count
//    OUTPUTS: nothing; value is returned by reference

void handle_single_entries(int entry_count, double& min_val, double& max_val, double& mean_val);
// PURPOSE: Allows the user to enter individual values and processed entered values
//    INPUTS: entry_count - integer value that represents the inputted entry count
//               min_val, max_val, mean_val - corresponding double value references
//    OUTPUTS: nothing; values are returned by reference

void output_stats(int entry_count, double min_val, double max_val, double mean_val);
// PURPOSE: output computed stats
//    INPUTS: entry_count - integer value that represents the inputted entry count
//               min_val, max_val, mean_val - corresponding double value
//    OUTPUTS: returns nothing; the output is to the console

void set_entry_count(int& entry_count) {
 // step1. allow the user to enter the count value that is greater than zero
    while (entry_count <= 0) {
        cout << "How many values would you like to enter? \n";
        cin >> entry_count;
    }
    // step2. output the result
    // nothing to do
    // alternative: return entry_count; with int as return value
}

void handle_single_entries(int entry_count, double& min_val, double& max_val, double& mean_val){
     // [setup] declare and initialize variables
    double current_entry = 0, sum_val = 0;
     // step1. allow the user to enter specified individual values
    for (int entry = 0; entry < entry_count; entry++) {
        // step1.1. allow the user to enter a single value
        cout << "What is your next value? \n";
        cin >> current_entry;
        
    // Objective: processed entered values
        // step 1.2. update the minimum value
        if (entry == 0 || current_entry < min_val) {
            min_val = current_entry;
        }
        //step1.3. update the maximum value
        if (entry == 1 || current_entry > max_val) {
                  max_val = current_entry;
        }
        //step1.4. update the summation value
        sum_val += current_entry;
    }
    // step2. update the mean value
    mean_val = sum_val / entry_count;
}

void output_stats(int entry_count, double min_val, double max_val, double mean_val){
    //step1. output computed stats
    cout << "\nThe resulting statistics: \n";
    cout << entry_count << " values were entered\n";
    cout << min_val << " is the minimum value\n";
    cout << max_val << " is the maximum value\n";
    cout << mean_val << " is the mean value\n";
}

void execute_ra6_q1();
//PURPOSE: Runs the steps of the specified program

void execute_ra6_q1() {
    // [setup] declare and initialize variables
    int entry_count = 0;
    double min_val = 0, max_val = 0, mean_val = 0;
    
    //[INPUT] step1. allow the user to set the entry count
    set_entry_count(entry_count);
    
    //[PROCESSING] step2. allow the user to enter individual values
    //             and processed entered values
    handle_single_entries(entry_count, min_val, max_val, mean_val);
    
    //[OUTPUT] step4. output computed stats
    output_stats(entry_count, min_val, max_val, mean_val);
}

int main() {
    execute_ra6_q1(); //invoke the execute function
}

