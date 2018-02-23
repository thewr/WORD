
//WORD_HEADER
/********************************************************************************************
Name: Ryan Thew   Z#:15156390
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: Due Time: 11:59 PM
Total Points: 25
Assignment 5: Linked List
Description:  Create linked list class plus node structure character.  supply it functions.
*********************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

#ifndef word_h
#define word_h

class character
{
	public:
		char symbol;
		character *next;
};

class WORD
{
	public:		
		// constructors & deconstructor
		WORD(); // default constructor.  terminate front and back of list.
		WORD(const string & s); // explicit-value constructor: string declaration is called here that will be created
		WORD(const WORD & org); // copy constructor:  used during a call by value, return or intialize declaration of word value. 
		~WORD();				//Destructor:  de-allocate all memory called by class creation. 
		// member function library
		int Length(); //Length:  character length of the word, the current object, is returned;  
		bool IsEqual(const WORD & B); // returns true if the two word objects are equal; otherwise false
		bool IsEmpty() { return front == 0; } // list is empty if first node isn't occupied 
		void Print();
		void Insert_Front(const char & key);  //insert at front of list
		void Insert_Back(const char & key); //insert at back of list
		void Remove(const char & key);
		// friend & overload functions
		friend ostream & operator<<(ostream & out, const WORD & wordObj); //Overload cout with object as link
		void operator=(const string & s);// Overload the assignment operation to take a full string, this will be the current object.
		WORD & operator=(const WORD & w) { WORD k; return k; } // overload assignment operator and recursively do something
		void operator+(const WORD & B); //Overload '+' operator as a member function so to chain the lists B to A	
		character* Search(const char & key);
		
	private:
		character * front, *back;
};



#endif