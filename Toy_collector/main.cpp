//
//  main.cpp
//  ra11
//
//  Created by Sydney LeBlanc on 2020-11-25.
//  Copyright © 2020 Sydney LeBlanc. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
/*
 Write a function that uses recursion to determine if the given number is a prime number.
 The smallest prime number is two. The function takes a single unsigned int as input,
 and returns true if the number is a prime and false otherwise. You need to use recursive
 helper functions. Do not use loops.
 */
int find_prime(unsigned int value, int divisor);
// PURPOSE: uses recursion to iternate through every number, and tests if the value
// is divisible by that number. if it is, that number is returned

bool is_prime(unsigned int value);
// PURPOSE: if the divisor returned by recursive function is the same as value,
// that means value is only divisble by itself, so it is a prime, returns true.

void q1(){
    int value;
    cout << "enter number: ";
    cin >> value;
    cout << value << (is_prime(value) ? " is prime\n" : " is NOT prime\n");
}

bool is_prime(unsigned int value){
    int divisor = 2;
    if (value == find_prime(value, divisor)) {
        return true;
    }
    else{
        return false;
    }
}

int find_prime(unsigned int value, int divisor){
   if (value % divisor == 0 || value <= 1) {
        return divisor;
    }
    else {
        return find_prime(value, divisor + 1);
    }
}

/*
 Write a function that finds the i-th twin prime pair of numbers. The twin prime is a
 number that is two more or two less than another prime number. The first such pair is (3, 5).
 The second pair is (5, 7). The function takes as input unsigned int and returns an instance of
 TwinPair structure. Each TwinPair contains two ints inside and it is initialized as (0, 0). You
 may assume that “bool is_prime(unsigned int n)” is available to call.
 */

struct TwinPair {
    int val1, val2;
    // initialize struct to (0,0)
    TwinPair() : val1(0), val2(0) {};
};

TwinPair find_twin_primes(int i, int value);

void q2(){
    int i, value = 3;
    TwinPair tp;
    cout << "enter number: ";
    cin >> i;
    
    tp = find_twin_primes(i, value);
    
    cout << "twin prime pair #" << i << " is (" << tp.val1 << ", " << tp.val2 << ")\n";
}

TwinPair find_twin_primes(int i, int value){
    TwinPair tp;
    int count = 0;
    
    while (count < i){
        // if both values are prime, increase twin pair count, place in struct
        if (is_prime(value) && is_prime(value + 2)) {
            count++;
            tp.val1 = value;
            tp.val2 = value + 2;
            
            // if the count is the same as desired pair number, return struct instance
            if (count == i) {
                return tp;
            }
        }
        // if not returned, increase the value and try again
        value++;
    }
    // had to return here bc it said it may reach the end of a non-void function
    return tp;
}
/*
Sophia has many toys. For each toy, she remembers the shape (e.g., elephant, porcupine, tiger), colour, and if it squeaks or not. Her parents are buying her new toys frequently but they keep forgetting to check for duplicates; at most, there can be two copies of each toy. It is time to get her a new toy and they would like to determine
(1) how many duplicate toys does Sophia have, and
(2) if the toy they are thinking of buying is already there in Sophia’s collection.
 */
#include "ToyCollection.cpp"

void q3(){
    ToyCollection Sophies_toys;
    Toy toy1 ("Rhino", "pink", "squeaky");
    Toy toy2 ("Giraffe", "yellow", "silent");
    Toy toy3 ("Rhino", "pink", "squeaky");
    Toy toy4 ("Bear", "pink", "squeaky");
    Toy toy5 ("Giraffe", "yellow", "silent");
    
    // test insertion, and removal if there are duplicates
    Sophies_toys.insert_toy(toy1);
    Sophies_toys.insert_toy(toy2);
    Sophies_toys.insert_toy(toy3);
    Sophies_toys.insert_toy(toy4);
    Sophies_toys.insert_toy(toy1);
    Sophies_toys.insert_toy(toy5);
    
    
    cout << "duplicates: " << Sophies_toys.count_duplicates() << endl;
}
int main() {
    q3();
}
