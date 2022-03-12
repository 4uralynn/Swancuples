#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include "words.h"

// Code 'Swancuples'
// Divide and Consider Decryption Tarot
// By |_4ura|_ynn
//
//The purpose of this program is to create the perfect virutal Tarot platform by giving the
//user the option for customizable, degradable, and otherwise "living", responsive decks. While physcial 
//limitations and card cut prevent this in non-virtual readings, tarot is meant to be divination 
//by story and art. While many virtual decks and reading apps exist, these do not take advantage of 
//the strengths of a virtual representation, particulartly the ability to customize in any way seen 
//fit. Other virtual decks and apps also do not seem to make any special effort to involve the 
//querient in the reading in ways that a typical reader in the present world cannot. Present and 
//degradable cards, shuffling techniques, and falling cards are all removed from the typical 
//app reading. In many card "games", this may seem like a plus, but Tarot is meant to be connective to 
//life and death. Weathering with use as the card energy builds and the relationship with the reader grows
//is very important.  This app seeks to feel more natural, while providing experiences and intuition that 
//will still feel otherworldly due to the connective and decryptive capabilities of the app. However,
//that otherworldly feeling should be an extension of that feeling you have when you walk in to have
//a reading done by your local witch. If the connections are right, however, that feeling can be even
//more pronounced with this app. This is the goal, along with vast customizability.
//While beginning decks will probably all have to be extra content made by myself or any other developers 
//who assist, the goal would be for users to be able to import desks, and maybe even their own artwork, 
//to use in their readings.
//
//
//This file is the header file for Card class and it's subclasses, Engender, Suit, Arcana, and Deck.

//Major Arcana will be calculated at MAJOR x ATYPE x [card number]
const int MAJOR = 1000, ATYPE = 50; // x 22 (totalling 2100 for "The World")
//Minor Arcana will be calculated per suit, and counted per card number. The face cards
//will be calculated with the addition of the suit, for example (WANDS + QUEEN) = 1260.
const int MINOR = 1100, WANDS = 1200, CUPS = 1400, SWORDS = 1600, COINS = 1800;
const int PAGE = 15, KNIGHT = 33, QUEEN = 60, KING = 100;



//Base class, the Tarot Card
class Card {
	public:
		Card();
		~Card();
		int arcanaOut();
		int suitOut();
		int numOut();
		int conditionOut();
		bool nameOut(char *);
		bool backartOut(char *);
		bool writeBackart(char *);
		bool writeCard(char *);
		bool writeNotes(char *);
		//bool replaceArt();
		
	protected:
		char * desc;
		char * notes;
		int condition;

	private:
		int * arcSNum;
		char * name;
		char * backart;
};

//Card Arrangement
class cardnode:public Card {
	public:
		cardnode();
		~cardnode();
		bool writePrev(cardnode *&);
		bool previous();
	protected:
		Card * data;
		cardnode * next;
	private:
		cardnode * prev;
};

//Derivative class "Engenderment" refers to how the cards propogate, whether by number or archetype
class Engender/*ment*/:public cardnode {
	public:
		Engender();
		~Engender();
		int push(Card *&);
		int pop(Card *&);
		int read(Card);
	protected:
		cardnode ** head1; 	//Stack ADT
		Engender * next;
	private:
		Wordnode * head2; 	//BST
		int top = 13;	
};		

//
class Suit:public Engender {
	public:
		Suit();
		~Suit();
		int push(Engender *&);
		int pop(Engender *&);
		int read(Card);
	protected:
		Engender **head3; //Stack ADT
		Suit * next;
		Suit * prev;
	private:
		Wordnode * wandroot; 	//BST
		Wordnode * cuproot;
		Wordnode * swordroot;
	 	Wordnode * coinroot;
		int top = 3;	
};

class Arcana {
	public:
		Arcana();
		~Arcana();
		int push(Suit *&);
		int pop(Suit *&);
		int read(Card);
	private:
		Suit ** head; 	//Array of Doubly linked lists 
				//(0-wands, 1-cups, 2-swords, 3-coins)
		Suit ** tail;
		Wordnode * root; //BST
};

class Deck:public cardnode{
	public:
		Deck();
		~Deck();
		int build();
		int dequeue();
		int dequeue(Card);
		int enqueue(Card);
		int peek(Card);
		int cardfall();
		int cardfall(Card);
		int shuffle();
		bool goodkarma();
		bool tradegy();


	private:			//Queue ADT
		cardnode * front;
		cardnode * rear;
};
