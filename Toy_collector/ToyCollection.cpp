//
//  ToyCollection.cpp
//  ra11
//
//  Created by Sydney LeBlanc on 2020-11-25.
//  Copyright © 2020 Sydney LeBlanc. All rights reserved.
//
#ifndef ToyCollection_cpp
#define ToyCollection_cpp
#include <stdio.h>
#include <iostream>
#include <vector>
#include "Toy.cpp"

using namespace std;


/*
 Sophia has many toys. For each toy, she remembers the shape (e.g., elephant, porcupine, tiger), colour, and if it squeaks or not. Her parents are buying her new toys frequently but they keep forgetting to check for duplicates; at most, there can be two copies of each toy. It is time to get her a new toy and they would like to determine (1) how many duplicate toys does Sophia have, and (2) if the toy they are thinking of buying is already there in Sophia’s collection.
 
 Second, design and implement the matching class ToyCollection that includes a <vector> of Toy instances, and int size(), void insert_toy(Toy& toy_info), bool remove_toys(Toy& toy_info), bool is_duplicate(Toy& toy_info), and int count_duplicates() methods.
 */
class Toy;
class ToyCollection {
    vector<Toy> toys;
    
public:
    
    ToyCollection(){};
   
    unsigned long int size(){
        return toys.size();
    }
    void insert_toy(Toy& toy_info){
        toys.push_back(toy_info);
        cout << "toy inserted\n";
    }
    void remove_toys(Toy& toy_info) {
        for (int i = 0; i <= toys.size(); i++) {
            if (toy_info == toys[i]) {
                toys.erase(toys.begin()+ i);
                i--;
            }
        }
    }
    bool is_duplicate(Toy& toy_info) {
        int copy_count = 0;
        for (int i = 0; i <= toys.size(); i++){
            if (toy_info == toys[i]) {
                copy_count++;
              
            }
        }
        return copy_count > 1;
    }
    
    int count_duplicates() {
        int duplicates = 0;
     for (int i = 0; i <= toys.size(); i++){
            if (is_duplicate(toys[i])) {
                duplicates++;
            }
        }
        return duplicates / 2;
    }
};

    
#endif /* ToyCollection_cpp */

