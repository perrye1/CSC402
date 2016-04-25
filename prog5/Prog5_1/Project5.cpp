/*
File Name: Project5.cpp
Author: Ethan Perry
Course/Project: CSC 402/502 Spring 2016, Project5
Purpose:  Project5 Catalog implementation
*/

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <iomanip>
#include <vector>
#include <stdlib.h>

#pragma once

using namespace std;

struct ItemInfo {
	string description;
	double  price;
	double weight;

	ItemInfo(string d = "Item not found", double p = 0.00, double w = 0.00) {
		description = d;
		price = p;
		weight = w;
	}
};

typedef map<std::string, ItemInfo> Catalog;
typedef map<std::string, int> Order;

void readCatalog(Catalog & catalog, const string & fileName) throw(runtime_error); // reads the input file and creates the catalog; throws a runtime_error if the file cannot be opened
void printCatalog(const Catalog & catalog); // prints the SKU, description, price, and weight of every item in the catalog
ItemInfo getItemData(const Catalog & catalog, const string & sku); // finds a single item by SKU and returns the details as a struct; returns a dummy struct with the description "Item not found", price 0.00, and weight 0.00 if the SKU is not in the catalog
void displayOrderItems(const Order & order, const Catalog & catalog); // Lists the SKU, description, and quantity of each type of order item
void addItem(Order & order, const Catalog & catalog, const string & sku, int quantity) throw (logic_error); // adds item(s) to the order; throws a logic_error if the item cannot be found in the catalog
void removeItem(Order & order, const string & sku, int quantity) throw (logic_error); // removes items(s) from the order; throws a logic_error if the item cannot be found in the order
void displayOrderSummary(const Order & order, const Catalog & catalog); // displays the number of unique item types, the total number of items, the total cost, and the total shipping weight

void main(){
	Catalog catalog;
	readCatalog(catalog, "Catalog.txt");
	printCatalog(catalog);
}

void readCatalog(Catalog & catalog, const string & fileName) throw(runtime_error){
	ifstream infile;
	try {
		infile.open(fileName);
	}
	catch (const runtime_error &e){
		cerr << " a runtime exception was caught, with message '" << e.what() << "'\n";
	}	
	string line = "";
	while (getline(infile, line)){
		vector<string> tokens;
		stringstream ss(line);
		string tmp = "";
		while (getline(ss, tmp, ':')){
			tokens.push_back(tmp);
		}
		ItemInfo item(tokens[1], stod(tokens[2], NULL), stod(tokens[3], NULL));
		catalog.insert(make_pair(tokens[0], item));
	}
}

void printCatalog(const Catalog & catalog){

	cout << setw(10) << left << "SKU";
	cout << setw(55) << left << "Description";
	cout << setw(12) << left << "Unit Price";
	cout << setw(25) << left << "Shipping Wt. (lbs.)";
	cout << endl;
	cout << setfill('=') << setw(100) << "=" << endl;
	cout << setfill(' ');

	for (Catalog::const_iterator iterator = catalog.begin(); iterator != catalog.end(); iterator++) {
		cout << setw(10) << left << iterator->first;
		cout << setw(55) << left << iterator->second.description;
		cout << setw(12) << fixed << setprecision(2) << left << iterator->second.price;
		cout << setw(25) << fixed << setprecision(1) << left << iterator->second.weight;
		cout << endl;
	}
}

ItemInfo getItemData(const Catalog & catalog, const string & sku){
	ItemInfo item;
	Catalog::const_iterator iterator = catalog.find(sku);
	if (iterator != catalog.end()){
		item = ItemInfo();
	}
	else{
		item = ItemInfo(iterator->second.description, iterator->second.price, iterator->second.weight);
	}
	return item;
}

void displayOrderItems(const Order & order, const Catalog & catalog){

}

void addItem(Order & order, const Catalog & catalog, const string & sku, int quantity){

}

void removeItem(Order & order, const string & sku, int quantity) throw (logic_error){

}

void displayOrderSummary(const Order & order, const Catalog & catalog){

}


