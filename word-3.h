
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
	bool IsEmpty(){ return front ==0;}
	
	//Length: Determines the length of the word A; remember A is the current object;
	int Length(); 
	
	//Overload the insertion operatoras a friend function with chaining to print a word A;
	friend ostream & operator<<(ostream & out, const WORD &){return out;} 
	
	//Overload the assignment operator as a member function to take a 
	//string (C-style or C++ string, just be consistent in your implementation) as an argument and 
	//assigns its value to A, the current object;
	void operator=(const string & s){}
	
	// Overload the assignment operator as a member function with chaining to take a word 
	//object as an argument and assigns its value to A, the current object;	               
	WORD & operator=(const WORD & w){WORD k; return k;} 
	
	//Overload the ‘+” operator as a member function without chaining to add word B     
    //(adds the set of symbols that makep B's linked list to the back of A's linked list) to the back of word A; 
	//remember A is the current object;                     
	void operator+(const WORD & B){} 
	
	//The default constructor will initialize your state variables. 
	//The front of the linked list is initially set to NULL or 0; this implies a non-header node 
	//implementation of the link list.	           
	WORD(){front = back =0; }  
	
   //Explicit-value constructor: This constructor will have one argument; 
   //a C-style string or a C++ string representing the word to be created;
	WORD(const string & s){ } 
	
	// Copy Constructor: Used during a call by value, return, or initialization/declaration of a word object;                           
    WORD(const WORD & org){}   
	
	//Destructor: The destructor will de-allocate all memory allocated for the word. Put the message 
	//"destructor called\n" inside the body of the destructor.
	~WORD(){}        

    // Returns true if two word objects are equal; otherwise false; remember A is the current      
	bool IsEqual(const WORD & B){return true;} 
	
	//Deletes the first occurrence of word B (removes the first set of characters that makeup B's linked 
    //list from A's linked list) from word A if it is there; remember A is the current object;
	void WORD::Remove(WORD & Org) {};
	
	//Removes all occurrences of word B (removes each set of characters that makeup B's linked 
    //list from A's linked list) from word A if it is there; remember A is the current object;
	void WORD::RemoveALL(WORD & Org) {};

private:
	character *front, *back;
};

#endif
