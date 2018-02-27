//WORD_DRIVER.CPP
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
#include <iomanip>

#include "word.h"



using namespace std;

int main()
{
	DRAW test_name;

	// test 1
	test_name.display("Test 1", "Default Constructor");
	WORD objA;
	cout << "objA list elements:  " << objA << endl;
	cout << endl;

	// test 2
	test_name.display("Test 2","Explicit Value Constructor");
	WORD objB("AA00AABB00");
	cout << "objB list elements:  " << objB << endl;
	cout << endl;

	// test 3
	test_name.display("Test 3", "Copy Constructor");
	WORD objC = objB;
	cout << "Copying objB into obC." << endl;
	cout << "objC list elements:  " << objC << endl;
	cout << endl;

	// test 4
	test_name.display("Test 4","Assigment Operator Overload I");
	WORD objD;
	objD = "ABA";
	cout << "ObjD set equal to \"ABA\"" << endl;
	cout << "objD list elements:  " << objD << endl;
	cout << endl;

	// test 5
	test_name.display("Test 5", "Assignment Operator Overload II");
	WORD objE;
	cout << "objE set equal to \"hello world\"." << endl;
	objE = "hello world";
	cout << "objE list elements:  " << objE << endl;
	cout << endl;

	// test 6
	test_name.display("Test 6","Length Function");
	cout << "Length of objA is " << objA.Length() << "." << endl;
	cout << "Length of objB is " << objB.Length() << "." << endl;
	cout << "Length of objC is " << objC.Length() << "." << endl;
	cout << "Length of objD is " << objD.Length() << "." << endl;
	cout << endl;


	// test 7
	test_name.display("Test 7","IsEqual Function");
	WORD objF,objG;
	cout << "objF set equal to \"AAFFOPLEKFF\" \nobjG equal to \"0A0\"." << endl;
	objF = "AAFFOPLEKFF";
	objG = "0A0XYZ";

	if (objF.IsEqual(objG)) {
		cout << "The 2 words are equal\n";
	}
	else {
		cout<<"The 2 words are not equal\n";
		}
	cout << endl;

	// test 8
	test_name.display("Test 8","Overload+ Operator");
	cout << "objH set as \"ABHAKJ\"." << endl;
	WORD objH("ABHAKJ");
	objH + objG;
	cout<<"objH followed by objG is \n"<<objH<<" = ABHAKJ0A0XYZ"<<endl;
	cout << endl;

	// test 9
	test_name.display("Test 9","Insert_Front/Insert_Rear");

	cout << "objG = " << objG << "     inserting \"W\" to front..." << endl;
	objG.Insert_Front('W');
	cout << "objG = " << objG << "    inserting \"Q\" to back..." << endl;
	objG.Insert_Back('Q');
	cout << "objG = " << objG << endl;
	cout << endl;

	// test 10
	test_name.display("Test 10","Remove/RemoveALL");
	WORD wordA("X12Z3Y412X3Z12Y3");
	WORD wordB("12345");

	cout << "wordA = " << wordA << "  ...  removing first of " << wordB << endl;
	wordA.Remove(wordB);
	cout << wordA << endl<<endl;


	cout << "wordA = " << wordA << "  ...  removingALL of " << wordB << endl;
	wordA.RemoveALL(wordB);
	cout << wordA << endl;

	system("pause");
	return 0;
}