//-------------------------------------------------------------------------------------------
// File: word.cpp
//-------------------------------------------------------------------------------------------
// Description:  Create linked list class plus node structure character.  supply it functions.
*********************************************************************************************/

#include <iostream>
#include <string>
#include "word.h"

using namespace std;


void DRAW::display(string NAME, string NAME2)
{
	//******** CREATE BORDER *************//
	LENGTH = NAME.length();
	SPACES = WIDTH / 2 - LENGTH / 2;
	//*********************************************************************************
	cout << char(CRNUPL) << setfill(char(HRZ2)) << setw(WIDTH) << char(HRZ2) << char(CRNUPR) << endl;
	cout << (char)VRT << setfill(' ') << setw(SPACES) << ' ' << NAME << setw(WIDTH - LENGTH - SPACES) << setfill(' ') << ' ' << (char)VRT << endl;
	cout << (char)VRTJL << setfill(char(HRZ1)) << setw(WIDTH) << char(HRZ1) << char(VRTJR) << endl;

	//******** CREATE BORDER *************//
	LENGTH = NAME2.length();
	SPACES = WIDTH/2-LENGTH/2;
	//*********************************************************************************
	cout << (char)VRT << setfill(' ') << setw(SPACES) << ' ' << NAME2 << setw(WIDTH - LENGTH - SPACES) << setfill(' ') << ' ' << (char)VRT << endl;
	cout << (char)CRNDWL << setfill(char(HRZ2)) << setw(WIDTH) << char(HRZ2) << char(CRNDWR) << endl;
}

//---------------------------------------------------------------------------------------------------------
// Name:  Length
// Precondition:  constructor called and list is initialized 
// Postcondition:  number of elements in list returned
// Descriton:	member function of WORD that returns an integer which is the number of elements inside list.
//---------------------------------------------------------------------------------------------------------
int WORD::Length()
{
	if (front == 0)
	{
		return 0;  // if first node isn't utilized return length of 0.
	}
	else
	{
		character *p = front;
		int count = 0;

		while (p != 0)  // traverse nodes until out of scope
		{
			count++;
			p = p -> next;  
		}
		return count;
	}

}

//---------------------------------------------------------------------------------------------------------
// Name:  Default Constructor
// Precondition:  Constructor object created 
// Postcondition:  private member values of WORD class are passed by value.
// Description:  intializes both front and back of list to point to NULL.
//---------------------------------------------------------------------------------------------------------
WORD::WORD() 
{
	cout << "Default Constructor Evoked!\n";
	front = back = 0;
}

//---------------------------------------------------------------------------------------------------------
// Name:  Deconstructor
// Precondition: Contructor called (default, copy, explicit) i.e. memory allocated to data structure
// Postcondition:  de-allocation of memory to data structure 
// Description:  removes potential memory leaks and spoke problems by releasing memory at close of program.
//---------------------------------------------------------------------------------------------------------
WORD::~WORD()
{
	cout << "Destructor Evoked!\n";
	while (front != 0)
	{
		character *p = front;
		front;
		front = front->next;
		delete p;
	}

}

//---------------------------------------------------------------------------------------------------------
// Name: Explicit Value Constructor
// Precondition: constructor called.  string function for class WORD tested and operating.
// Postcondition:  string is stored inside data structure as a linked list.
// Description:  allocates memory for string called explicitly inside constructor.
//---------------------------------------------------------------------------------------------------------
WORD::WORD(const string & s)
{
	cout << "Explicit Value Constructor Evoked!" << endl;
	if (s.length() == 0)
	{
		front = back = 0;
		return;
	}

	front = new character;
	character *p = front;

	int i = 0;
	while (i < s.length()-1)
	{
		p->symbol = s[i++];
		p->next = new character;
		p=p -> next;
	}
	p->symbol = s[i];
	p->next = 0;
}

//---------------------------------------------------------------------------------------------------------
// Name: void Print()
// Precondition: constructor called and something or nothing is contained inside linked list.
// Postcondition:  char symbol is passed to cout until terminal node is met.
// Description:  prints the contents of the linked list to screen.
//---------------------------------------------------------------------------------------------------------
void WORD::Print()//accessor
{
	character *p = front;

	cout<<endl<<endl;


	while( p != 0) // while not inside terminated node 
	{
		cout << p-> symbol << endl;
		p = p->next;
	}
    cout<<endl<<endl;
}

//---------------------------------------------------------------------------------------------------------
// Name: void Insert_Front
// Precondition: constructor evoked.  a word has been stored.
// Postcondition: node character added to the front of list with input char key 
// Description:  inserts a new character to the front of the word stored.
//---------------------------------------------------------------------------------------------------------
void WORD::Insert_Front(const char & key)
{
	character *p = new character;

    p->next =0;
    p->symbol = key;

	if (front == 0)
	{
		front = p;
		back = front;
	}
	else
	{		
		p->next = front;
		front = p;
	}

}

//---------------------------------------------------------------------------------------------------------
// Name: void Insert_Back
// Precondition: constructor evoked.  a word has been stored.
// Postcondition: node character added to the back of list with input char key 
// Description:  inserts a new character to back front of the word stored.
//---------------------------------------------------------------------------------------------------------
void WORD::Insert_Back(const char & key)
{	
	character *p = new character;
	p->symbol = key;
	p->next = 0;

	if (front == 0)
	{
		front = new character;
		front->symbol = key;
		front->next = 0;
		back = front;
	}
	else
	{
		character* q = front;
		while (q->next)
		{
			q = q->next;

		}
		q->next = p;

	}


}

//---------------------------------------------------------------------------------------------------------
// Name: character* WORD Search
// Precondition: constructor evoked.  a word has been stored.
// Postcondition:  returns index of char key node's location.
// Description:  used to search for node index of a character.
//---------------------------------------------------------------------------------------------------------
character* WORD::Search(const char & key)
{
	character *p = front;  // list node to front

	while(p!=0)			// while node is not empty
	{
		if (p->symbol == key)   // if match
		{
			return p;			// return location of node
		}
		p = p->next;			// go to next node
	}
	return p;

}

//---------------------------------------------------------------------------------------------------------
// Name: operator<< overloading
// Precondition: word stored in constructor object wordObj.
// Postcondition:  wordObj passed to cout returns contents of the array.
// Description:  displays contents of wordObj when using std::cout.
//---------------------------------------------------------------------------------------------------------
ostream & operator<<(ostream & out, const WORD & wordObj)
{
	character *p = wordObj.front;

	while (p != 0)
	{
		out << p->symbol;
		p = p->next;
	}
	return out;
}

//---------------------------------------------------------------------------------------------------------
// Name: Copy Constructor
// Precondition:  original word stored in linked list data structor via constructor evoke.  
// Postcondition:  contents of original word is passed into newly created wordObj when both are set equal.
// Description:  allows for new word object to be given content of another.  i.e. objA = "XYZ", objB = objA; 
//---------------------------------------------------------------------------------------------------------
WORD::WORD(const WORD & org)
{
	cout << "Copy Constructor Evoked!" << endl;
	character *p = new character;  //ptr for current
	character *q = new character;  //ptr for original

	if (front == 0)
	{
		front = p;			// all ptrs point to single node
		back = front;
	}
	else
	{
		p->next = front;  // traverse ptr through list
		front = p;
	}

	if (org.front == 0)
	{
		front = 0;
	}
	else
	{
		front = new character;
		front->symbol = org.front->symbol;
		p = front;
		q = org.front->next;
	}

	while (q)
	{
		p->next = new character;
		p = p->next;
		p->symbol = q->symbol;
		q =q->next;
	}
	p->next = 0;
}

//---------------------------------------------------------------------------------------------------------
// Name: operator= overloading
// Precondition: constructor called for object. object set equal to string in word_driver.cpp
// Postcondition:  stores the string passed into object into it's linked list structure.
// Description: calls = operator to set object equal to string.  stores string.               
//---------------------------------------------------------------------------------------------------------
void WORD::operator=(const string & s)
{
	cout << "Overload = Evoked!" << endl;
	if (s.length() == 0)
	{
		front = back = 0;
		return;
	}

	front = new character;
	character *p = front;

	int i = 0;
	while (i < s.length() - 1)
	{
		p->symbol = s[i++];
		p->next = new character;
		p = p->next;
	}
	p->symbol = s[i];
	p->next = 0;
}

//---------------------------------------------------------------------------------------------------------
// Name: bool IsEqual
// Precondition: constructor called for WORD A and B
// Postcondition:  bool set to true is equal otherwise false
// Description:  arguments to determine whether two strings are the same.
//---------------------------------------------------------------------------------------------------------
bool WORD::IsEqual(const WORD & B) 
{
	character *p = new character;  // ptr for wordObjA
    character *q = new character;  // ptr for wordObjB
	
	p = front;  // pting to front of wordObjA
	q = B.front; // pting to front of wordObjB

	while (p && q && p->symbol == q->symbol)
	{
		p = p->next;
		q = q->next;
		return true;
	}

	return false;


}  // returns true if the two word objects are equal; otherwise false

//---------------------------------------------------------------------------------------------------------
// Name: overload operator(+)
// Precondition: constructor called for WORD A.  Operator(+) before B. 
// Postcondition:  WORD B is copied to the back of WORD A.
// Description:  overload + constructor to "paste" strings.
//---------------------------------------------------------------------------------------------------------
void WORD::operator+(const WORD & B)
{
	character *p = B.front;  // point to front of string B
	
	while (p != 0) {
		Insert_Back(p->symbol);  // insert behind string A
		p=p->next;   // go to next till done
	}
	
}

//---------------------------------------------------------------------------------------------------------
// Name: void Remove
// Precondition: word stored in constructor.  Search function operating.
// Postcondition:  node of the key word returned by search is removed.
// Description:  deletes a word B from A; current object.
//---------------------------------------------------------------------------------------------------------
void WORD::Remove(WORD & org)
{
	char key;
	character *p = new character;  // points to word A to be deleted of word B
	character *q = new character;  // points to word B
	p = org.front;
	q = p;

	while(q!=0)
	{
		key = q->symbol;
		p = Search(key);   // find location of item to remove

		if (p == 0)   //if search returns no index i.e. no match.  do nothing.
		{
			cout << "character " << key << " not in list...moving on\n";	
		}
		else          //otherwise locate index of match
		{
			
			if (p == front && front == back)    //if single node delete and terminate list
			{
				delete p;
				front = back = 0;
			}
			else if (p == front)				//if front of list.  move node back and delete old front.
			{
				front = front->next;
				delete p;
			}
			else                      //otherwise locate random node position and delete
			{
				character *back_ptr = front;

				while (back_ptr != 0 && back_ptr->next != p)
				{
						back_ptr = back_ptr->next;
				}
				if (p == back)
				{
					back = back_ptr;
				}
				back_ptr->next = p->next;
				delete p;
			}
		}
		p = new character;
		q = q->next;
	}
}

//-------------------------------------------------------------------------------------
// Name: RemoveALL
// Precondition: Constructor Called.
// Postcondition:  Current object state is changed while B remains the same.
// Description:  Remove ALL occurences of word object B from A.
void WORD::RemoveALL(WORD & org)
{
	char key;

	character *p = new character;  // points to word A to be deleted of word B
	character *q = new character;  // points to word B
	p = org.front;
	q = p;

	while(p != 0)
	{		
		while (q != 0)
		{
				key = q->symbol;
				p = Search(key);   // find location of item to remove

			if (p == 0)   //if search returns no index i.e. no match.  do nothing.
			{
				cout << "character " << key << " not in list...moving on\n";
			}
			else          //otherwise locate index of match
			{

				if (p == front && front == back)    //if single node delete and terminate list
				{
					delete p;
					front = back = 0;
				}
				else if (p == front)				//if front of list.  move node back and delete old front.
				{
					front = front->next;
					delete p;
				}
				else                      //otherwise locate random node position and delete
				{
					character *back_ptr = front;

					while (back_ptr != 0 && back_ptr->next != p)
					{
						back_ptr = back_ptr->next;
					}
					if (p == back)
					{
						back = back_ptr;
					}
					back_ptr->next = p->next;
					delete p;
				}
			}
			p = new character;
			q = q->next;
		}

		p = new character;
		q = new character;
		p = org.front;
		q = p;
		key = q->symbol;
		p = Search(key);   // find location of item to remove
	}
	delete p;
	q->next = 0;

}
