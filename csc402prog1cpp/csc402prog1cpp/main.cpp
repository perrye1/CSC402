/*
File Name: main.cpp
Author: Perry, Ethan
Course: CSC 402
Date: 02/08/16
*/

#include "sort.h"

void main() {

	srand(time(0));

	int array1 [SIZE];
	vector<int> array2;

	for (int i = 0;i < SIZE;i++) {
		array1[i] = rand() % 32767;
		array2.push_back(rand() % 32767);
	}

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	sortNative(array1);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	sortFixed(array2);
	high_resolution_clock::time_point t4 = high_resolution_clock::now();

	auto duration1 = duration_cast<milliseconds>(t2 - t1).count();
	auto duration2 = duration_cast<milliseconds>(t4 - t3).count();

	cout << "C++: Sorting the native array took " << duration1 << "ms, and sorting the fixed array took " << duration2 << "ms." << " Size was " << SIZE << "." << endl;

}