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
    
    srand(static_cast<unsigned int>(time(nullptr)));
    
    ofstream fout;
    fout.open("sieteymedio.txt", ios::out | ios::trunc);
    
    int game = 1;
    
    while (you->get_money() > 0 && you -> get_money() < 1000) {
        
        Hand* yourHand = new Hand();
        Hand* dealersHand = new Hand();
        
        fout << "-----------------------------------------------" << endl << endl;
        fout << left << "Game Number: " << left << game;
        fout << setw(30) << right << "Money Left: " << you->get_money() << endl;
        
        cout << "You have $" << you->get_money()<< ". Enter bet: ";
        double bet;
        cin >> bet;
        cout << endl;
        if (bet > you->get_money()) {
            cout << "You only have $" << you->get_money() << ". Please bet less than $" << you->get_money() << "." << endl;
            cout << "Enter bet: ";
            cin >> bet;
            cout << endl;
        }
        fout << "Bet: $" << bet << endl;
        
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
        
        cout << endl << "Dealer's turn." << endl;
        

        while (dealersHand->get_value() < 5.5) {
            dealersHand->draw();
            Card* newest = dealersHand->get_card(dealersHand->size()-1);
            cout << "New Card: " << endl;
            cout << "        ";
            newest->print_card();
            cout << endl;
            cout << "Dealer's Cards:" << endl;
            dealersHand->print_deck();
        }
        
        cout << "The dealer's total is " << dealersHand->get_value() << "." << endl << endl;
        
        // result of round
        // Case 1: you come closer to 7½ than the dealer or the dealer busts but you did not bust
        if ((yourHand->get_value() <= 7.5 && yourHand->get_value() > dealersHand->get_value()) ||
            (yourHand->get_value() <= 7.5 && dealersHand->get_value() >= 7.5))
        {
            cout << "You win $" << bet << "." << endl << endl;
            you->update_money(bet);
        }
        // Case 2: dealer comes closer to 7½ than you, or the you bust
        else if ((dealersHand->get_value() <= 7.5 && dealersHand->get_value() > yourHand->get_value()) || (dealersHand->get_value() <= 7.5 && yourHand->get_value() >= 7.5))
        {
            cout << "Too bad. You lose $" << bet << "." << endl << endl;
            you->update_money(-1*bet);
        }
        // Case 3: both you and the player bust
        else if (dealersHand->get_value() > 7.5 && yourHand->get_value() > 7.5)
        {
            cout << "Too bad. You lose $" << bet << "." << endl << endl;
            you->update_money(-1*bet);
        }
        // Case 4
        else if (dealersHand->get_value() == yourHand->get_value() && yourHand->get_value() <= 7.5) {
            cout << "Nobody wins!" << endl << endl;
        }
        
        fout << "Your Cards: " << endl;
        yourHand->file_deck(fout);
        fout << "Your total: " << yourHand->get_value() << endl << endl;
        fout << "Dealer's Cards: " << endl;
        dealersHand->file_deck(fout);
        fout << "Dealer's total: " << dealersHand->get_value() << endl << endl;
        
            game++;
        
        delete yourHand;
        delete dealersHand;
    }
    
    fout.close();
    
   return 0;
}
