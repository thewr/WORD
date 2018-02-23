
#include <iostream>
#include <string>
using namespace std;

#ifndef WORD_H
#define WORD_H

class character
{
public:
char symbol;
character *next;
};

class WORD
{
public:
	//IsEmpty: 
	//Returns true if front is NULL otherwise false.
	bool IsEmpty(){ return front ==0;}
	
	//Length: 
	//Determines the length of the word A; remember A is the current object;
	int Length(); 
	
	//Overload the insertion operator:
	//prints state of word A;
	friend ostream & operator<<(ostream & out, const WORD &){return out;} 
	
	//Overload the assignment operator:  
	//takes a string as an argument and assigns its value to A, the current object;
	void operator=(const string & s){}
	
	//Overload the assignment operator:  
	//include chaining to take a word object as an argument and assigns its value to A, the current object;	               
	WORD & operator=(const WORD & w){WORD k; return k;} 
	
	//Overload+ operator:  
	//includes the ‘+” operator as a member function without chaining to add word B to the back of word A;              
	void operator+(const WORD & B){} 
	
	//Default Constructor: 
	//initialize state variables.  Front and back of linked list is set to NULL.          
	WORD(){front = back =0; }  
	
        //Explicit-value constructor: 
	//Constructor with one argument; a string type representing word to be created.
	WORD(const string & s){ } 
	
	//Copy Constructor: 
	//Used during a call by value, return, or initialization/declaration of a word object;                           
    	WORD(const WORD & org){}   
	
	//Destructor: 
	//The destructor will de-allocate all memory allocated for the word.
	~WORD(){}        

   	//IsEqual:
	//Returns true if two word objects are equal; otherwise false; remember A is the current      
	bool IsEqual(const WORD & B){return true;} 
	
	//Remove:
	//Deletes the first occurrence of word B (removes the first set of characters that makeup B's linked 
        //list from A's linked list) from word A if it is there; remember A is the current object;
	void WORD::Remove(WORD & Org) {};
	
	//RemovesALL:
	//Deleters all occurrences of word B (removes each set of characters that makeup B's linked 
        //list from A's linked list) from word A if it is there; remember A is the current object;
	void WORD::RemoveALL(WORD & Org) {};

private:
	character *front, *back;
};

#endif
