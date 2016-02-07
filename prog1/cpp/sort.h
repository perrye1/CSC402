/*
File Name: sort.h
Author: Perry, Ethan
Course: CSC 402
Date: 02/08/16
*/

#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include <chrono>
#define SIZE 10000

using namespace std;
using namespace std::chrono;

void sortNative(int *ar);
void sortFixed(vector<int> &ar);
