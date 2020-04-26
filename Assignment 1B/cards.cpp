//
//  cards.cpp
//  Assignment 1B
//
//  Created by Iris Bai on 4/22/20.
//  Copyright © 2020 Iris Bai. All rights reserved.
//

#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

/*
You might or might not need these two extra libraries

#include <algorithm>
*/


/* *************************************************
   Card class
   ************************************************* */

/*
   Default constructor for the Card class.
   It could give repeated cards. This is OK.
   Most variations of Blackjack are played with
   several decks of cards at the same time.
*/
Card::Card(){
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break;
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break;
      default: break;
   }

   r = 1 + rand() % 10;
   switch (r) {
      case  1: rank = AS; break;
      case  2: rank = DOS; break;
      case  3: rank = TRES; break;
      case  4: rank = CUATRO; break;
      case  5: rank = CINCO; break;
      case  6: rank = SEIS; break;
      case  7: rank = SIETE; break;
      case  8: rank = SOTA; break;
      case  9: rank = CABALLO; break;
      case 10: rank = REY; break;
      default: break;
   }
}

// Accessor: returns a string with the suit of the card in Spanish
string Card::get_spanish_suit() const {
   string suitName;
   switch (suit) {
      case OROS:
         suitName = "oros";
     break;
      case COPAS:
         suitName = "copas";
     break;
      case ESPADAS:
         suitName = "espadas";
     break;
      case BASTOS:
         suitName = "bastos";
     break;
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish
string Card::get_spanish_rank() const {
   string rankName;
   switch (rank) {
      case AS:
         rankName = "As";
     break;
      case DOS:
         rankName = "Dos";
     break;
      case TRES:
         rankName = "Tres";
     break;
      case CUATRO:
         rankName = "Cuatro";
     break;
      case CINCO:
         rankName = "Cinco";
     break;
      case SEIS:
         rankName = "Seis";
     break;
      case SIETE:
         rankName = "Siete";
     break;
      case SOTA:
         rankName = "Sota";
     break;
      case CABALLO:
         rankName = "Caballo";
     break;
      case REY:
         rankName = "Rey";
     break;
      default: break;
   }
   return rankName;
}

// Accessor: returns a string with the suit of the card in English
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
    string suitName;
    switch (suit) {
       case OROS:
          suitName = "golds";
      break;
       case COPAS:
          suitName = "cups";
      break;
       case ESPADAS:
          suitName = "spades";
      break;
       case BASTOS:
          suitName = "clubs";
      break;
       default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in English
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
    string rankName;
    switch (rank) {
       case AS:
          rankName = "Ace";
      break;
       case DOS:
          rankName = "Two";
      break;
       case TRES:
          rankName = "Three";
      break;
       case CUATRO:
          rankName = "Four";
      break;
       case CINCO:
          rankName = "Five";
      break;
       case SEIS:
          rankName = "Six";
      break;
       case SIETE:
          rankName = "Seven";
      break;
       case SOTA:
          rankName = "Jack";
      break;
       case CABALLO:
          rankName = "Queen";
      break;
       case REY:
          rankName = "King";
      break;
       default: break;
    }
    return rankName;
}

// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}

void Card::print_card() const {
    string spanish_name = get_spanish_rank() + " de " + get_spanish_suit();
    cout << left << setw(20) << spanish_name;
    string english_name = "(" + get_english_rank() + " of " + get_english_suit() + ")";
    cout << right << setw(15) << english_name;
}

void Card::file_card(ofstream& fout) const {
    string spanish_name = get_spanish_rank() + " de " + get_spanish_suit();
    fout << left << setw(20) << spanish_name;
    string english_name = "(" + get_english_rank() + " of " + get_english_suit() + ")";
    fout << right << setw(15) << english_name;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
   return rank < card2.rank;
}



/* *************************************************
   Hand class
   ************************************************* */
// Implement the member functions of the Hand class here.
    
double Hand:: get_value() const{
    return value;
}

Card* Hand:: get_card(size_t pos) const {
    return deck[pos];
}
    
size_t Hand:: size() const{
    return deck.size();
}
    
double Hand:: update_value(double card_value) {
    value = value + card_value;
    return value;
}

vector<Card*> Hand::draw() {
    Card* newest = new Card();
    deck.push_back(newest);
    
    if (newest->get_rank() <= 7){
        this->update_value(newest->get_rank());
    }
    else {this->update_value(0.5);}
    
    return deck;
}

void Hand::print_deck() const {
    for (Card* val: deck) {
    cout << "        ";
    val->print_card();
    cout << endl;
    }
}
    
void Hand::file_deck(ofstream& fout) const {
    for (Card* val: deck) {
    fout << "        ";
    val->file_card(fout);
    fout << endl;
    }
}


/* *************************************************
   Player class
   ************************************************* */
// Implement the member functions of the Player class here.
    
double Player::get_money() const {
    return money;
}
    
double Player::update_money(double change) {
    money = money + change;
    return money;
}
