//
//  CurrencyAmountCDN.cpp
//  ra10
//
//  Created by Sydney LeBlanc on 2020-11-24.
//  Copyright © 2020 Sydney LeBlanc. All rights reserved.
//
/*
 The class needs to include two private integer attributes, dollars and cents. Implement default constructor with no parameters that sets both integer attributes to 0, and one parametric constructor that sets the values based on the inputted double amount (e.g., 55.25 is stored as 55 dollars and 25 cents). If the inputted amount is negative, then default amount of 0 is stored for both attributes.
 Implement public methods for adding and subtracting two CDN currency amounts, where another CurrencyAmountCDN instance is provided as the parameter value to each method. If the resulting value is negative, then the default amount of 0 is stored for both attributes. Furthermore, add a public method called print() that will output current value stored in the object.
 */
#include "CurrencyAmountCDN.hpp"

using namespace std;

CurrencyAmountCDN::CurrencyAmountCDN() : dollars(0), cents(0) {} // free to do other tasks

CurrencyAmountCDN::CurrencyAmountCDN(double new_value) {
     int new_dollars;
     if (new_value > 0) {
         dollars = new_value;
         new_dollars = new_value * 100;
         cents = new_dollars % 100;
     }
     else {
         CurrencyAmountCDN();
     }
 }
\

void CurrencyAmountCDN::increment_value(int add_dollars, int add_cents){

      int new_cents_value = (dollars + add_dollars) * 100 + (cents + add_cents);
       dollars = new_cents_value / 100;
       cents = new_cents_value % 100;
}

void CurrencyAmountCDN::increment_value(CurrencyAmountCDN add_values){
    increment_value(add_values.dollars, add_values.cents);
    
}

void CurrencyAmountCDN::decrement_value(int sub_dollars, int sub_cents){
    increment_value(-sub_dollars, -sub_cents);
}

void CurrencyAmountCDN::decrement_value(CurrencyAmountCDN sub_value){
    increment_value(-sub_value.dollars, -sub_value.cents);
}

void CurrencyAmountCDN::CDN_to_USD(){
   
    double new_cdn_value = dollars + (cents / 100);
    double usd_value = USD_ER * new_cdn_value;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "$" << dollars << "." << cents << " CAD is $" << usd_value << " USD\n";
}

void CurrencyAmountCDN::CDN_to_EUR(){
  
    double new_cdn_value = dollars + (cents / 100);
    double usd_value = EUR_ER * new_cdn_value;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "$" << dollars << "." << cents << " CAD is €" << usd_value << " EUR\n";
}

void CurrencyAmountCDN::print(){
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "New value is: $" << dollars << "." << cents << endl;
}
