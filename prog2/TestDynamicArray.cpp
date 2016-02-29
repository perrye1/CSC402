/*
File Name: TestDynamicArray.cpp
Author: Perry, Ethan
Course: CSC 402
Date: 02/29/16
*/

#include "DynamicArray.h"

int main() {
	DynamicArray d1;
	cout << "--------constructed a new default DynamicArray (d1)----------" << endl;
	d1.diag();
	d1.push_back(4);
	cout << "----------pushed 4 on to d1----------" << endl;
	d1.diag();
	d1.push_back(7);
	cout << "----------pushed 7 on to d1----------" << endl;
	d1.diag();
	d1.insert(1, 6);
	cout << "----------inserted 6 at position 1 in d1----------" << endl;
	d1.diag();
	cout << "----------printing d1 using the << overload----------" << endl;
	cout << d1 << endl;
	cout << "----------finding 6 in d1...----------" << endl;
	cout << "6 is at poition: " << d1.find(6) << endl;
	d1.pop_back();
	cout << "----------popped from d1----------" << endl;
	d1.diag();
	cout << "----------is d1 empty?----------" << endl;
	cout << d1.empty() << endl;
	d1.clear();
	cout << "----------cleared d1, is it empty now?----------" << endl;
	cout << d1.empty() << endl;

	DynamicArray d2(20);
	cout << "--------constructed a new DynamicArray (d2) with capacity of 20----------" << endl;
	d2.diag();

	int iArr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	DynamicArray d3(iArr, 10);
	cout << "--------constructed a new DynamicArray (d3) from a primative----------" << endl;
	d3.diag();

	d1 = d3;
	cout << "--------used the operator= overload to assign d3 to d1----------" << endl;
	d1.diag();

	cout << "--------is d1 equal to d3? (using == overload)----------" << endl;
	cout << (d1 == d3) << endl;

	DynamicArray d4(d3);
	cout << "--------copy constructed a new DynamicArray (d4) from d3----------" << endl;
	d4.diag();

	cout << "--------destroying the DynamicArray objects as they pass out of scope----------" << endl;

}