//
//  Toy.cpp
//  ra11
//
//  Created by Sydney LeBlanc on 2020-11-25.
//  Copyright © 2020 Sydney LeBlanc. All rights reserved.
//

#ifndef Toy_cpp
#define Toy_cpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

/*
 Sophia has many toys. For each toy, she remembers the shape (e.g., elephant, porcupine, tiger), colour, and if it squeaks or not. Her parents are buying her new toys frequently but they keep forgetting to check for duplicates; at most, there can be two copies of each toy. It is time to get her a new toy and they would like to determine
 (1) how many duplicate toys does Sophia have, and
 (2) if the toy they are thinking of buying is already there in Sophia’s collection.
 
 First, design and implement the corresponding class Toy that includes the required data attributes,
 empty constructor, parametric constructor, getter methods, and overloaded operator ==.
 */
class Toy {
    string shape, colour, squeak;
    
public:
    //default constructor
    Toy();
    
    //parametric constructor
    Toy(string new_shape, string new_colour, string new_squeak) :
    shape(new_shape), colour(new_colour), squeak(new_squeak){}
    
    //simple geetter methods
    string get_shape(){
        return shape;
    }
    string get_colour() {
        return colour;
    }
    string get_squeak() {
        return squeak;
    }
    
    // overloaded operator == to check for duplicates in collection
    bool operator== (Toy new_toy) const{
        if (shape == new_toy.shape && colour == new_toy.colour && squeak == new_toy.squeak) {
            return true;
        }
        else {
            return false;
        }
    }
};


#endif /* Toy_cpp */
