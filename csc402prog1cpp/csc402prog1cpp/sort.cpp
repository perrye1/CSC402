/*
File Name: sort.cpp
Author: Perry, Ethan
Course: CSC 402
Date: 02/08/16
*/

#include "sort.h"

void sortNative(int *ar)
{
	int i, j, first, temp;
	int numLength = SIZE;
	for (i = numLength - 1; i > 0; i--)
	{
		first = 0;                 // initialize to subscript of first element
		for (j = 1; j <= i; j++)   // locate smallest between positions 1 and i.
		{
			if (ar[j] < ar[first])
				first = j;
		}
		swap(ar[first], ar[i]);
	}
	return;
}

void sortFixed(vector<int> &ar)
{
	int i, j, first, temp;
	int numLength = ar.size();
	for (i = numLength - 1; i > 0; i--)
	{
		first = 0;                 // initialize to subscript of first element
		for (j = 1; j <= i; j++)   // locate smallest between positions 1 and i.
		{
			if (ar[j] < ar[first])
				first = j;
		}
		swap(ar[first], ar[i]);	
	}
	return;
}
