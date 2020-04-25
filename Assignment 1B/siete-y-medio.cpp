//
//  main.cpp
//  Assignment 1B
//
//  Created by Iris Bai on 4/22/20.
//  Copyright © 2020 Iris Bai. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)

// Non member functions implementations (if any)


// Stub for main
int main(){
   /* --STATEMENTS-- */
    Player* you = new Player();
    Player* dealer = new Player();
    Hand* yourHand = new Hand();
    Hand* dealersHand = new Hand();
    
    srand(static_cast<unsigned int>(time(nullptr)));
    
    cout << "You have $100. Enter bet: ";
    double bet;
    cin >> bet;
    cout << endl;
    if (bet > you->get_money()) {
        cout << "You only have $" << you->get_money() << ". Please bet less than $" << you->get_money() << "." << endl;
        cout << "Enter bet: ";
        cin >> bet;
        cout << endl;
    }

    yourHand->draw();
    cout << "Your Cards:" << endl;
    yourHand->print_deck();

    char response;
    cout << "Your total is " << yourHand->get_value() << ". Do you want another card (y/n)? ";
    cin >> response;

    while(response == 'y') {
        yourHand->draw();
        Card* newest = yourHand->get_card(yourHand->size()-1);
        cout << "New Card: " << endl;
        cout << "        ";
        newest->print_card();
        cout << endl;
        cout << "Your Cards:" << endl;
        yourHand->print_deck();

        if (yourHand->get_value() < 7.5) {
        cout << "Your total is " << yourHand->get_value() << ". Do you want another card (y/n)? ";
        cin >> response;
        }
        else {response = 'n';}
    }

    while (dealersHand->get_value() < 5.5) {
        dealersHand->draw();
    }
  
    cout << "Dealer's Cards:" << endl;
    dealersHand->print_deck();
    cout << "The dealer's total is " << dealersHand->get_value() << "." << endl;
 
   return 0;
}
