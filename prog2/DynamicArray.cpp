/*
File Name: DynamicArray.cpp
Author: Perry, Ethan
Course: CSC 402
Date: 02/29/16
*/

#include "DynamicArray.h"

//default constructor
DynamicArray::DynamicArray(int cap) {
	_capacity = cap;
	_size = 0;
	_arr = new int[cap];
}

//constructor from primative array
DynamicArray::DynamicArray(int *_iArr, int length) {
	_capacity = length;
	_size = length;
	_arr = new int[length];
	for (int i = 0; i < length; i++) {
		_arr[i] = _iArr[i];
	}
}

//copy constructor
DynamicArray::DynamicArray(DynamicArray &_dArr) {
	if ((this != &_dArr) && !(_dArr.empty())) {
		_size = _dArr.size();
		_capacity = _dArr.capacity();
		_arr = new int[_dArr.capacity()];
		for (int i = 0; i < _dArr.size(); i++) {
			_arr[i] = _dArr[i];
		}
	}
}

//destructor
DynamicArray::~DynamicArray(){
	delete[] _arr;
	cout << "destroyed a DynamicArray object" << endl;
}

//copy assignment operator overload
void DynamicArray::operator=(DynamicArray &_dArr) {
	if (this != &_dArr) {
		if (_dArr.size() >= (_capacity*0.8)) {
			int *_tmp = new int[_dArr.size() * 2];
			_capacity = _dArr.size() * 2;
			_size = _dArr.size();
			delete[] _arr;
			_arr = _tmp;
		}
		for (int i = 0; i < _dArr.size(); i++) {
			_arr[i] = _dArr[i];
		}
	}
}

//overload [] for getting the value at an index	
int DynamicArray::operator [](int i) const { //overload [] for get
	return _arr[i];
}

//return the size of the array
int DynamicArray::size() {
	return _size;
}

//return the total capacity of the array
int DynamicArray::capacity() {
	return _capacity;
}

//check if the array is empty
bool DynamicArray::empty() {
	return _size == 0;
}

//return the frontmost value
int DynamicArray::front() {
	if (!_size == 0) {
		return _arr[0];
	}
	else {
		return -INT_MAX;
	}
}

//return the rearmost value
int DynamicArray::back() {
	if (!_size == 0) {
		return _arr[_size-1];
	}
	else {
		return -INT_MAX;
	}
}

//finds the first index that a value appears at
int DynamicArray::find(int val) {
	for (int i = 0; i < _size; i++) {
		if (_arr[i] == val) {
			return i;
		}
	}
	return -1;
}

//sets the size to 0
void DynamicArray::clear() {
	_size = 0;
}

//pushes a value onto the back of the array
void DynamicArray::push_back(int val) {
	if (_size >= (_capacity*0.8)) {
		int *_tmp = new int[_capacity * 2];
		_capacity = _capacity * 2;
		delete[] _arr;
		_arr = _tmp;
	}
	_arr[_size] = val;
	_size++;
}

//inserts a value at the specified index
int DynamicArray::insert(int pos, int val) {
	if (_size >= (_capacity*0.8)) {
		int *_tmp = new int[(_capacity * 2)];
		_capacity = _capacity * 2;
		delete[] _arr;
		_arr = _tmp;
	}
	for (int i = pos; i < _size; i++) {
		_arr[i + 1] = _arr[i];
	}
	_size++;
	_arr[pos] = val;
	if (_arr[pos] == val) {
		return pos;
	}else {
		return -1;
	}
}

//removes the rearmost value
void DynamicArray::pop_back() {
	_size--;
}

//prints some diagnostics about the array
void DynamicArray::diag() {
	cout << "capacity: " << capacity() << endl;
	cout << "size: " << size() << endl;
	cout << "front: " << front() << endl;
	cout << "back: " << back() << endl;
}

//overload the == operator for testing equality
bool operator==(DynamicArray &_dArr1, DynamicArray &_dArr2) {
	if (_dArr1.size() == _dArr2.size()) {
		for (int i = 0; i < _dArr1.size(); i++) {
			if (_dArr1[i] != _dArr2[i]) {
				return false;
			}
		}
	}else {
		return false;
	}
	return true;
}

//overload the << operator for chaining into a print statement
ostream & operator<<(ostream & out, DynamicArray &value){
	for (int i = 0; i < value.size(); i++) {
		if (i != value.size() - 1) {
			cout << value[i] << ",";
		}else {
			cout << value[i];
		}
	}
	return out;
}