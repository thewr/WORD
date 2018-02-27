
//WORD_HEADER
/********************************************************************************************
Assignment 5: Linked List
Description:  Create linked list class plus node structure character.  supply it functions.
*********************************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#ifndef word_h
#define word_h

/* DEFINE ASCII SYMBOLS FOR DRAW */
#define VRT   186   // ║
#define HRZ2  205   // ═
#define HRZ1 196
#define CRNUPL 201  
#define CRNUPR 187
#define CRNDWL 200
#define CRNDWR 188 
#define VRTJL 199
#define VRTJR 182

class DRAW
{
public:
	DRAW() { WIDTH = 65;}
	~DRAW() {};
	void display(string NAME, string NAME2);
private:
	int WIDTH, LENGTH, SPACES;
};


class character
{
	public:
		char symbol;
		character *next;
};

class WORD
{
	public:		
	//Default Constructor:  Intiatialize private member's values.  
		WORD();
	//Explicit-Value Constructor:  String declaration called within function argument will be intialized here.  
		WORD(const string & s);
	//Copy Constructor:  
		WORD(const WORD & org); // copy constructor:  used during a call by value, return or intialize declaration of word value. 
	//Destructor:  deallocate all memory called in class creation. 
		~WORD();				
	//Overload the insertion operator:  print state word of A;
		friend ostream & operator<<(ostream & out, const WORD & wordObj);
	//Overload the assignment operator: takes a string as an argument and assigns its value to A, the current object;
		void operator=(const string & s);// Overload the assignment operation to take a full string, this will be the current object.
	//Overload the assignment operator: takes a word object as an argument and assigns its value to A, the current object;	   		
		WORD & operator=(const WORD & w) { WORD k; return k; } // overload assignment operator and recursively do something
	//Overload+ operator:  ‘+' operator as a member function without chaining to add word B to the back of word A;
		void operator+(const WORD & B); 
	//Search:  Find location of node with character;
		character* Search(const char & key);
	//Length: Determines the length of the word A; remember A is the current object; 
		int Length();		
	//IsEqual: returns true if the two word object are equal; otherwise false 
		bool IsEqual(const WORD & B); 
	//IsEmpty: returns true if front is NULL; otherwise false
		bool IsEmpty() { return front == 0; }
	//Print: print contents of linked-list.
		void Print();
	//Insert_Front:  Create new node at front and insert character there.
		void Insert_Front(const char & key);  
	//Insert_Back: Create new node at back and insert character there.
		void Insert_Back(const char & key); 
	//Remove: Removes first occurence of word B from A; the current object
		void Remove(WORD & org);
	//Remove_All:  Removes all the occurences of word B from A; the current object
		void RemoveALL(WORD & Org);
	private:
		character * front, *back;
};



#endif
