//
// Student name: Sydney LeBlanc
//
// SYDE 121 assignment: 2
// file name: drop_distance_calc
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: distance calculator
// Purpose: Determine the distance a ball has fallen in 30 seconds
//          and the time to fall 15000m
//
// Due date: October 9, 2020
//***************************************************

/*
Program will work for any distance and time less than 10^308 (max of double)
Assuming distance and time are positive
For step1, tested times values of  60, 100, 2500, 10000
For step2, tested distance values of 1000, 4412, 20000, 500000
Confirmed all outputs through an online caclulator, results were the same
*/

#include <iostream>

using namespace std;

void total_distance(double time, double& distance);
// PURPOSE: Determines the total distance the ball has fallen each second
// INPUT: time – corresponding double value
//        distance – corresponding double value reference
// OUTPUT: returns nothing; value is returned by reference

void  step1_distance_in_thirty(double time, double distance, double previous_distance);
// PURPOSE: Output stats for the ball distance in 30 seconds
// INPUT: time, previous_distance – corresponding double value
//        distance – corresponding double value
// OUTPUT: returns nothing; the output is to the console

void step2_drone_distance(double time, double distance, double previous_distance);
// PURPOSE: Output stats for the time to drop 15000
// INPUT: time, previous_distance – corresponding double value
//        distance – corresponding double value
// OUTPUT: returns nothing; the output is to the console

void execute_distance_calculator();
// PURPOSE: execute the steps of the program

void total_distance(double time, double& distance) {
    // declare constant
    const double GRAVITY = 9.80665;
    
    // compute the distance from the given formula
    distance = 0.5 * GRAVITY * time * time;
}

void step1_distance_in_thirty(double time, double distance, double previous_distance) {
    // step1. Output header and column headers
    cout << "Distance the ball drops in 30 seconds:\n"
    "\nTime (in sec):  Distance during interval (in m):  Total Distance (in m): \n";
    
    // step2. Ouput time, distance intervals and total distance
    for (double time = 0; time <= 30; time++) {
        
        // step2.1 update the previous distance and calculate total distance
        previous_distance = distance;
        total_distance(time, distance);
        
        // step2.2 output stats
        cout << time << "                " << distance - previous_distance
            << "                            " << distance << endl;
    }
}

void step2_drone_distance(double time, double distance, double previous_distance){
     // step1. Output header and column headers
     cout << "\nTime it takes to drop from 15000m:\n"
     "\nTime (in sec):  Distance during interval (in m):  Total Distance (in m): \n";

     // step2. Ouput time, distance intervals and total distance until distance of 15000m
    do {
        // step2.1 update the previous distance and calculate total distance
        previous_distance = distance;
        total_distance(time, distance);
        
        //step2.2 output stats
        cout << time << "                " << distance - previous_distance
        << "                            " << distance << endl;
        
        // step2.3 Decrease time interval from 1s to 0.1 after 14000m
        if (distance < 14000) {
            time = time + 1;
        }
        else {
        time = time + 0.1;
        }
    } while (distance < 15000);
}

    
void execute_distance_calculator() {
    // declare and intialize variables
    double distance = 0;
    double time = 0;
    double previous_distance = 0;
    
    // set precision to 3 decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    
    // Step1, Determine distance in 30 seconds
    step1_distance_in_thirty(time, distance, previous_distance);
    
    // Step2. Determine time in 15000m from drone
    step2_drone_distance(time, distance, previous_distance);
}

int main() {
    execute_distance_calculator();
}
