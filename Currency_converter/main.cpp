//
//  main.cpp
//  ra10
//
//  Created by Sydney LeBlanc on 2020-11-12.
//  Copyright © 2020 Sydney LeBlanc. All rights reserved.
//

#include <iostream>
#include "CurrencyAmountCDN.hpp"
using namespace std;

class CurrencyAmountCDN;

void test_add_currency(){
    CurrencyAmountCDN ca1(12.50), ca2(5.50), ca3(-1.50), ca4(15.00);
    cout << "Test adding CAD currencies:\n";
    ca1.increment_value(ca2);
    ca1.print();
    ca2.increment_value(ca3);
    ca2.print();
    ca3.increment_value(ca4);
    ca3.print();
}

void test_sub_currency(){
    CurrencyAmountCDN ca1(12.50), ca2(5.50), ca3(-1.50), ca4(15.00);
    cout << "\nTest subtracting CAD currencies:\n";
    ca1.decrement_value(ca2);
    ca1.print();
    ca3.decrement_value(ca4);
    ca3.print();
    ca2.decrement_value(ca3);
    ca2.print();
}

void test_exchange(){
    CurrencyAmountCDN ca1(12.50), ca2(5.50), ca3(-1.50);
    cout << "\nTest converting CAD currencies into USD and EUR:\n";
    ca1.CDN_to_USD();
    ca2.CDN_to_EUR();
    ca3.CDN_to_EUR();
    ca3.CDN_to_USD();
}

int main() {
    test_add_currency();
    test_sub_currency();
    test_exchange();
    
}
