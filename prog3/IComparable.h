/*
File Name: IComparable.h
Author: Ethan Perry
Course/Project: CSC 402/502 Spring 2016, Project3
Purpose:  IComparable declaration and implementation
*/

#include <iostream>
#pragma once

using namespace std;

class IComparable
{
public:

	~IComparable() {}

	virtual const IComparable & operator= (const IComparable & rhs) {
		return *this; // dummy implementation
	}

	virtual int compare(const IComparable & icmp) const = 0 ;		//abstract definition of compare

	virtual void print(ostream & out = cout) const = 0 ;			//abstract definition of print

	bool operator< (const IComparable & rhs) const {				//operator < overload
		return (compare(rhs) == -1);	
	}
	bool operator> (const IComparable & rhs) const {				//operator > overload
		return (compare(rhs) == 1);
	}
	bool operator== (const IComparable & rhs) const {				//operator == overload
		return (compare(rhs) == 0);
	}
	bool operator!= (const IComparable & rhs) const {				//operator != overload
		return !(compare(rhs) == 0);
	}
	bool operator<= (const IComparable & rhs) const {				//operator <= overload
		return !(compare(rhs) == 1);
	}
	bool operator>= (const IComparable & rhs) const {				//operator >= overload
		return !(compare(rhs) == -1);
	}
};

class Integer : public IComparable
{
private: 

	int value;														//data member to store value being wrapped

public:

	Integer(int initialValue = 0) {									//constructor
		value = initialValue;
	}

	Integer(const IComparable &rhs) {								//copy constructor
		value = dynamic_cast<const Integer &>(rhs).value;
	}

	const IComparable & operator= (const IComparable & rhs) {		//operator = overload
		if (this != &rhs) {
			value = dynamic_cast<const Integer &>(rhs).value;
		}	
		return *this;
	}

	int compare(const IComparable & icmp) const {					//compares two Integer objects
		int temp = dynamic_cast<const Integer &>(icmp).value;

		if (value > temp) {return 1;}
		else if (value < temp) {return -1;}
		else {return 0;}
	}

	void print(ostream & out = cout) const {						//prints an Integer object
		out << value;
	}

};

class Character : public IComparable
{
private:

	char value;														//data member to store value being wrapped

public:

	Character(char initialValue = '?') {							//constructor
		value = initialValue;
	}

	Character(const IComparable &rhs) {								//copy constructor
		value = dynamic_cast<const Character &>(rhs).value;
	}

	const IComparable & operator= (const IComparable & rhs) {		//operator = overload
		if (this != &rhs) {
			value = dynamic_cast<const Character &>(rhs).value;
		}
		return *this;
	}

	int compare(const IComparable & icmp) const {					//compares two Character objects
		int temp = dynamic_cast<const Character &>(icmp).value;

		if (value > temp) { return 1; }
		else if (value < temp) { return -1; }
		else { return 0; }
	}

	void print(ostream & out = cout) const {						//prints a Character object 
		out << value;
	}

};

ostream& operator<< (ostream &out, const IComparable & rhs) {		//global overload of << for streaming output to cout
	rhs.print(); 
	return out;
}
