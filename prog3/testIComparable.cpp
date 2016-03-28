/*
File Name: testIComparable.cpp
Author: Tim McCord
Course/Project: CSC 402/502 Spring 2016, Project3
Purpose:  Common test driver to be used for grading
*/

#pragma warning( disable : 4018 ) 

#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>             // CSC 502    
#include "IComparable.h"



// CSC 502 students should uncomment this preprocessor directive for the extra requirement.  
//#define CSC502

using namespace std;

// forward declarations
void print(const vector<IComparable *>  & v);
void sort(vector<IComparable *> & v);
bool isSorted(const vector<IComparable *> & v);

const string SEPARATOR = "=========================================";

int main()
{
	// seed the random number generator
	srand(static_cast<unsigned int>(time(NULL)));
	// convenient way to test with different size vectors
	const size_t SIZE = 100;

	// TEST CASES

	cout << endl << "Stack-based Integer constructors, =, and << tests:" << endl << SEPARATOR << endl;

	Integer i1;   // should set the value to the default 0 
	cout << "i1 = " << i1 << endl;
	Integer i2 = 10;
	cout << "i2 = " << i2 << endl;
	// Copy constructor
	Integer i3 = i2;
	cout << "i3 = " << i3 << endl;
	// = operator
	Integer i4;
	i4 = i3;
	cout << "i4 = " << i4 << endl;


	cout << endl << "Integer relational operator tests:" << endl << SEPARATOR << endl;
	(i1 < i2) ? cout << "i1 < i2" << endl : cout << "ERROR: i1 <  i2 should be true" << endl;
	(i1 != i2) ? cout << "i1 != i2" << endl : cout << "ERROR: i1 != i2 should be true" << endl;
	(i1 <= i2) ? cout << "i1 <= i2" << endl : cout << "ERROR: i1 <= i2 should be true" << endl;
	(i1 == i1) ? cout << "i1 == i1" << endl : cout << "ERROR: i1 == i1 should be true" << endl;

	(i2 > i1) ? cout << "i2 > i1" << endl : cout << "ERROR: i2 >  i1 should be true" << endl;
	(i2 == i3) ? cout << "i2 == i3" << endl : cout << "ERROR: i2 == i3 should be true" << endl;
	(i2 >= i1) ? cout << "i2 >= i1" << endl : cout << "ERROR: i2 >= i1 should be true" << endl;
	(i3 >= i3) ? cout << "i3 >= i3" << endl : cout << "ERROR: i3 >= i3 should be true" << endl;

	(i4 == i3) ? cout << "i4 == i3" << endl : cout << "ERROR: i4 == i3 should be true" << endl;

	cout << endl;

	cout << endl << "Stack-based Character constructors, =, and << tests:" << endl << SEPARATOR << endl;
	Character c1;   // should be the default (?) 
	cout << "c1 = " << c1 << endl;
	Character c2('A');
	cout << "c2 = " << c2 << endl;
	Character c3 = c2;
	cout << "c3 = " << c3 << endl;
	Character c4;
	c4 = c3;
	cout << "c4 = " << c4 << endl;
	cout << endl;

	cout << endl << "Character relational operator tests:" << endl << SEPARATOR << endl;
	(c1 < c2) ? cout << "c1 < c2" << endl : cout << "ERROR: c1 <  c2 should be true" << endl;
	(c1 != c2) ? cout << "c1 != c2" << endl : cout << "ERROR: c1 != c2 should be true" << endl;
	(c1 <= c2) ? cout << "c1 <= c2" << endl : cout << "ERROR: c1 <= c2 should be true" << endl;
	(c1 == c1) ? cout << "c1 == c1" << endl : cout << "ERROR: c1 == c1 should be true" << endl;

	(c2 > c1) ? cout << "c2 > c1" << endl : cout << "ERROR: c2 >  c1 should be true" << endl;
	(c2 == c3) ? cout << "c2 == c3" << endl : cout << "ERROR: c2 == c3 should be true" << endl;
	(c2 >= c1) ? cout << "c2 >= c1" << endl : cout << "ERROR: c2 >= c1 should be true" << endl;
	(c3 >= c3) ? cout << "c3 >= c3" << endl : cout << "ERROR: c3 >= c3 should be true" << endl;

	(c4 == c3) ? cout << "c4 == c3" << endl : cout << "ERROR: c4 == c3 should be true" << endl;
	cout << endl;


	// To support runtime polyporphism, we'll need to be able to handle IComparable pointers
	//   in addition to stack-allociated instances of IComparable subclasses

	cout << endl << "Integer test cases using IComparable pointers" << endl << SEPARATOR << endl;
	IComparable *ip1 = new Integer;      // default constuctor
	IComparable *ip2 = new Integer(1);
	cout << "*ip1 = " << *ip1 << endl;
	cout << "*ip2 = " << *ip2 << endl;

	cout << endl << "Integer copy construction using IComparable references" << endl << SEPARATOR << endl;
	IComparable *ip3 = new Integer(10);
	IComparable *ip4 = new Integer(*ip3);
	cout << "*ip3 = " << *ip3 << endl;
	cout << "*ip4 = " << *ip4 << endl;
	(*ip3 == *ip4) ? cout << "*ip3 == *ip4" << endl : cout << "ERROR: *ip3 == *ip4 should be true" << endl;
	cout << endl;

	cout << endl << "Integer copy assignment operators using IComparable references" << endl << SEPARATOR << endl;
	*ip2 = *ip1;
	cout << "*ip1 = " << *ip1 << endl;
	cout << "*ip2 = " << *ip2 << " after copy assignment " << endl;
	(*ip1 == *ip2) ? cout << "*ip1 == *ip2" << endl : cout << "ERROR: *ip1 == *ip2 should be true" << endl;
	cout << endl;


	cout << endl << "Character test cases using IComparable pointers" << endl << SEPARATOR << endl;
	IComparable *cp1 = new Character('Z');
	IComparable *cp2 = new Character('A');
	cout << "*cp1 = " << *cp1 << endl;
	cout << "*cp2 = " << *cp2 << endl;

	cout << endl << "Character copy construction using IComparable references" << endl << SEPARATOR << endl;
	IComparable *cp3 = new Character('F');
	IComparable *cp4 = new Character(*cp3);
	cout << "*cp3 = " << *cp3 << endl;
	cout << "*cp4 = " << *cp4 << endl;
	(*cp3 == *cp4) ? cout << "*cp3 == *cp4" << endl : cout << "ERROR: *cp3 == *cp4 should be true" << endl;
	cout << endl;

	cout << endl << "Character copy assignment operators using IComparable references" << endl << SEPARATOR << endl;
	*cp2 = *cp1;
	cout << "*cp1 = " << *cp1 << endl;
	cout << "*cp2 = " << *cp2 << " after copy assignment " << endl;
	(*cp1 == *cp2) ? cout << "*cp1 == *cp2" << endl : cout << "ERROR: *cp1 == *cp2 should be true" << endl;
	cout << endl;

	

	cout << endl << "Vector of IComparable pointers initialized as Integers" << endl << SEPARATOR << endl;
	vector<IComparable*> intVector;
	// initialize withe random primitive ints + single-arg constructor
	for (int i = 0; i < SIZE; i++)
		intVector.push_back(new Integer(rand()));

	cout << endl << "intVector before sorting:" << endl << SEPARATOR << endl;
	print(intVector);
	cout << "isSorted(intVector)? (0 for false, 1 for true): " << isSorted(intVector) << endl;

	// local sort function 
	sort(intVector);

#ifdef CSC502 
	std::sort(intVector.begin(), intVector.end(), LessThan());
#endif

	cout << endl << "intVector after sorting:" << endl << SEPARATOR << endl;
	print(intVector);
	cout << endl;
	cout << "isSorted(intVector): " << isSorted(intVector) << endl;

	cout << endl << "Vector of IComparable pointers initialized as Characters" << endl << SEPARATOR << endl;
	vector<IComparable*> charVector;
	// initialize with ASCII characters in the range 33 - 127 only
	for (int i = 0; i < SIZE; i++)
		charVector.push_back(new Character(rand() % 95 + 33));

	cout << endl << "charVector before sorting:" << endl << SEPARATOR << endl;
	print(charVector);
	cout << "isSorted(charVector)? (0 for false, 1 for true): " << isSorted(charVector) << endl;
	cout << endl;

	// local sort function
	sort(charVector);

#ifdef CSC502  
	std::sort(charVector.begin(), charVector.end(), LessThan());
#endif 

	cout << endl << "charVector after sorting:" << endl << SEPARATOR << endl;
	print(charVector);
	cout << endl;
	cout << "isSorted(charVector): " << isSorted(charVector) << endl;
	cout << endl;


	cout << endl << "Bonus content demonstrating the use of std::sort:" << endl << SEPARATOR << endl;
	cout << endl;
	// using std::sort out of the box with a vector of Integers
	vector<Integer> v;
	for (int i = 10; i > 0; i--)
		v.push_back(i);
	cout << "Unsorted vector of Integer objects (not IComparables!!!!)" << endl << SEPARATOR << endl;
	for (size_t i = 0; i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;

	std::sort(v.begin(), v.end());

	cout << "After std::sort:" << endl << SEPARATOR << endl;
	for (int i = 0; (size_t)i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;


	// cleanup
	for (unsigned int i = 0; i < SIZE; i++) {
		delete intVector[i];
		delete charVector[i];
	}

	delete ip1, ip2, ip3, ip4, cp1, cp2, cp3, cp4;

	cin.get();  // portable pause
	return 0;
}
// My auxilliary functions

void print(const vector<IComparable *>  & v)
{
	// if the vector is larger than a certain size, print only the first
	// ten elements and the last ten
	int size = v.size();
	if (size > 100) {
		for (int i = 0; i < 10; i++)
			cout << *v[i] << "\t";

		cout << " ... " << endl;

		for (int i = 0; i < 10; i++)
			cout << *v[size - (i + 1)] << "\t";

		cout << endl;
	}
	else {
		for (auto item : v)   // auto requires C++11 compiler
			cout << *item << "\t";
		cout << endl;
	}
}

// Selection sort, swapping pointers exclusively 
void sort(vector<IComparable *> & v) {
	int i, j, min;
	IComparable *tmp;

	for (j = 0; j < v.size(); j++) {
		min = j;
		for (i = j + 1; i < v.size(); i++) {
			// NOTE the use of the overloaded < operator
			if (*v[i] < *v[min]) {
				min = i;
			}
		}
		if (min != j) {
			tmp = v[j];
			v[j] = v[min];
			v[min] = tmp;
		}
	}
}

bool isSorted(const vector<IComparable *> & v) {
	bool sorted = true;
	for (int i = 1; i < v.size(); i++)
		if (*(v[i]) < *(v[i - 1])) {
			sorted = false;
			break;
		}
	return sorted;
}