/*
File Name: DynamicArray.h
Author: Perry, Ethan
Course: CSC 402
Date: 02/29/16
*/

#pragma once
#include <climits>
#include <iostream>
using namespace std;

class DynamicArray {

private:
	int _capacity;												//the total capacity of the array
	int _size;													//the current size of the array
	int *_arr;													//pointer to the primative array that we are wrapping

public:
	DynamicArray(int cap = 10);									//default constructor
	DynamicArray(int *_iArr, int length);						//constructor from primative array
	DynamicArray(DynamicArray &_dArr);							//copy constructor
	~DynamicArray();											//destructor
	void operator=(DynamicArray &_dArr);						//copy assignment operator overload
	int operator [](int i) const;								//overload [] for getting the value at an index	
	int size();													//return the size of the array
	int capacity();												//return the total capacity of the array
	bool empty();												//check if the array is empty
	int front();												//return the frontmost value
	int back();													//return the rearmost value
	int find(int val);											//finds the first index that a value appears at
	void clear();												//sets the size to 0
	void push_back(int val);									//pushes a value onto the back of the array
	int insert(int pos, int val);								//inserts a value at the specified index
	void pop_back();											//removes the rearmost value
	void diag();												//prints some diagnostics about the array
};

bool operator==(DynamicArray &_dArr1, DynamicArray &_dArr2);	//overload the == operator for equality
ostream & operator<<(ostream & out, DynamicArray &value);		//overload the << operator for chaining into a print statement