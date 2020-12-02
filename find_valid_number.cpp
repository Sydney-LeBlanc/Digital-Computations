//
//
//  Created by Sydney LeBlanc on 2020-10-01.
//  Copyright © 2020 Sydney LeBlanc. All rights reserved.
//

#include <iostream>

using namespace std;

void number_solver(){
    
    //step1. declare and initialize variables
    int valid_number = 0;
    const int MAX_VALUE = 9999;
    
    //step2. interate through values 0 to 9999
    for (int entry = 0; entry <= MAX_VALUE; entry += 1) {
        
        //step2.1. check if all four digits are different
        bool valid_entry = entry / 1000 != entry % 1000 / 100 && entry / 1000 !=
            entry % 100 /10 && entry / 1000 != entry % 10 && entry % 1000 / 100
            != entry % 100 /10 && entry % 1000 / 100 != entry % 10 && entry % 100 /10
            != entry % 10;
        
        //step2.2. check if the digit in the thousands place is three times
        // the one in the tens place
        valid_entry = valid_entry && (entry / 1000) == (entry % 100 /10) * 3;
        
        //step2.3. check if it is odd
        valid_entry = valid_entry && entry % 2 != 0;
        
        //step2.4. check if the sum of digits equals 27
        valid_entry =  valid_entry && (entry / 1000) + (entry % 1000 / 100) +
        (entry % 100 /10) + (entry % 10) == 27;
        
        //step2.5 output the solution
        if (valid_entry)
        cout << "The solution to the puzzle is: "<< entry << endl;
        
        //step2.6 keep iterating to find other solutions if possible
        valid_number++;
    }
}

int main() {
    number_solver();
}
