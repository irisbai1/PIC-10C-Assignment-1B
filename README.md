# PIC-10C-Assignment-1B
PIC 10C Assignment 1B card game

This is the code for the card game Siete y Medio. Record of game play will be stored in sieteymedio.txt.

cards.h
This is the file for the interfaces for the Card, Hand, and Player class
	
	Card class
	holds the suit and rank of each card
	
	Hand class
	holds the Cards that the player has and the total value of the cards
	
	Player class
	holds the money that the Player has
	
cards.cpp
This is the file for all the member function definitions of the Card, Hand, and Player classes.

siete-y-medio.cpp
This is th source file for the implementation of the game

How To Play
Goal: Have the value of your cards be as close to but less than or eaqual to 7.5 as possible. If the value goes over 7.5, you bust.
1. The player starts with $100.
2. Enter the amount you want to bet. Must be less than the amount you have.
3. The game will draw you a card. Decide if you want to draw another card. Enter 'y' or 'n'.
4. When your turn is over, the dealer will have thier turn.
5. At the end of each round, game decides who wins.
6. Keep playing more rounds until you run out of money or dealer loses $900.
