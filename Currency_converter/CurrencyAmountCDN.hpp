//
//  CurrencyAmountCDN.hpp
//  ra10
//
//  Created by Sydney LeBlanc on 2020-11-24.
//  Copyright © 2020 Sydney LeBlanc. All rights reserved.
//

/*
 The class needs to include two private integer attributes, dollars and cents. Implement default constructor with no parameters that sets both integer attributes to 0, and one parametric constructor that sets the values based on the inputted double amount (e.g., 55.25 is stored as 55 dollars and 25 cents). If the inputted amount is negative, then default amount of 0 is stored for both attributes.
 */
#ifndef CurrencyAmountCDN_hpp
#define CurrencyAmountCDN_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class CurrencyAmountCDN {
    int dollars, cents;
    const double USD_ER = 0.77;
    const double EUR_ER = 0.65;
    
public:
    CurrencyAmountCDN();
    CurrencyAmountCDN(double new_value);
    
    void input(double new_value);
    
    void increment_value(int new_dollars, int new_cents);
    void increment_value(CurrencyAmountCDN add_values);
  
    void decrement_value(int new_dollars, int new_cents);
    void decrement_value(CurrencyAmountCDN sub_values);
    
    void CDN_to_USD();
    void CDN_to_EUR();
    
    void print();

};

#endif /* CurrencyAmountCDN_hpp */
