//
// Student name: Sydney LeBlanc
//
// SYDE 121 assignment: 1
// file name: balance_scale
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: balance scale
// Purpose: Counts the amount of each weight required to weigh an object
// Due date: September 25, 2020

#include <iostream>

using namespace std;

void balance_scale() {
    // Variable declarations
    // for step1, weight_given = 2048
    int weight_given, weights125, weights75, weights42,
    weights15, weights1;
    
    // Get input from user
    // assume user enters a positve integer value
    // cannot be larger than 2^31
    cout << "Enter initial weight: ";
    cin >> weight_given;
    
    // Perform the computation and validate the results
    // Checked using a calculator the values for 2048
    weights125 = weight_given / 125;                // 2048 / 125 = 16.3 = 16
    weights75 = weight_given % 125 / 75;            // 2048 - (16 * 125) / 75 = 0
    weights42 = weight_given % 125 % 75 / 42;       // 48 / 42 = 1.1 = 1
    weights15 = weight_given % 125 % 75 % 42 / 15;  // 48 - (42 * 1 ) / 15 = 0
    weights1 = weight_given % 125 % 75 % 42  % 15;  // 6 / 1 = 6
  
    // Output the results
     cout << "Amount of each weight required for " << weight_given
        << " lb: \n 125 lb: " << weights125 << "\n 75 lb: "
        << weights75 << "\n 42 lb: " << weights42 << "\n 15 lb: "
        << weights15 << "\n 1 lb: " << weights1 << endl;
        // Output for 2048 was same as calculator results:
        // 125 lb: 16
        // 75 lb: 0
        // 42 lb: 1
        // 15 lb: 0
        // 1 lb: 6
        // program worked for test values: 58, 167, 745, 8148, 14795
        // confirmed using a calculator
}

int main() {
    balance_scale();
    
    return 0;
}
