//
// Student name: Sydney LeBlanc
//
// SYDE 121 assignment: 1
// file name: sum_calculator
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: sum calculator
// Purpose: Calculate the sum from one integer to another integer
// Due date: September 25, 2020

#include <iostream>

using namespace std;

void sum_calculator() {
    // variable declarations
    // sum must be less than 2^31
    double first_number, last_number, total_integers, sum;
    
    // get input from user
    // assume user enters a positive integer, where the first
    // integer is less than the last integer
    cout << "Enter the first integer: ";
    cin >> first_number;
    cout << "Enter the last integer: ";
    cin >> last_number;
    
    // perform the computation and validate the results
    total_integers = (last_number - first_number) + 1;
    sum = (total_integers / 2.0) * ((2 * first_number) + (total_integers - 1));
    
    // output the results
    cout << "The sum of " << first_number << " to " << last_number <<
        " is " << sum << endl;
    // outputs for:
    // 1 to 500 = 125250
    // 5 to 2020 = 2.0412e+06
    // 42 to 32000 = 5.12015e+08
    // confirmed by an online calculator, however the results were not rounded
    // so 5 to 2020 = 2041200 and 42 to 32000 = 512015139
}

int main() {
    sum_calculator();
    
    return 0;
}
