/*
File Name: Comparable.h
Author: Ethan Perry
Course/Project: CSC 402/502 Spring 2016, Project4
Purpose:  Comparable declaration and implementation
*/

#include <iostream>
#pragma once

using namespace std;


template <typename T>
class Comparable {

	// ASSUMPTIONS:

	// There is no suitable built-in type such as int, double, etc.,
	// to serve as the default parameter, but we can assume
	// something and create a default (no-arg) constructor.

	// for compare, we assume that what items passed in have an inate 
	// value that we can compare with typical math operators

	// for print, we assume that ostream supports outputting the items that we pass in

public:

	Comparable(const T & initialValue = T()){							//default no-arg constructor
		value = initialValue;
	}

	Comparable(const Comparable &rhs) {								//copy constructor
		value = rhs.value;
	}

	const Comparable & operator= (const Comparable & rhs) {			//operator = overload
		if (this != &rhs) {
			value = rhs.value;
		}
		return *this;
	}

	bool operator< (const Comparable & rhs) const {					//operator < overload
		return (compare(rhs) == -1);
	}
	bool operator> (const Comparable & rhs) const {					//operator > overload
		return (compare(rhs) == 1);
	}
	bool operator== (const Comparable & rhs) const {					//operator == overload
		return (compare(rhs) == 0);
	}
	bool operator!= (const Comparable & rhs) const {					//operator != overload
		return !(compare(rhs) == 0);
	}
	bool operator<= (const Comparable & rhs) const {					//operator <= overload
		return !(compare(rhs) == 1);
	}
	bool operator>= (const Comparable & rhs) const {					//operator >= overload
		return !(compare(rhs) == -1);
	}

	void print(ostream & out = cout) const {							//prints a T object
		out << value;
	}

	int compare(const Comparable & icmp) const {						//compares two T objects
		T temp = icmp.value;

		if (value > temp) { return 1; }
		else if (value < temp) { return -1; }
		else { return 0; }
	}

private:

	T value;

};

template <typename T> ostream& operator<< (ostream &out, const Comparable<T> &rhs) {		//global overload of << for streaming output to cout
	rhs.print();
	return out;
};


