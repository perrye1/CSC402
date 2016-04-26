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

// struct defining an item
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

// typedefs for the Order and Catalog
typedef map<string, ItemInfo> Catalog;
typedef map<string, int> Order;

// forward declarations
void readCatalog(Catalog & catalog, const string & fileName) throw(runtime_error);
void printCatalog(const Catalog & catalog);
ItemInfo getItemData(const Catalog & catalog, const string & sku);
void displayOrderItems(const Order & order, const Catalog & catalog);
void addItem(Order & order, const Catalog & catalog, const string & sku, int quantity) throw (logic_error);
void removeItem(Order & order, const string & sku, int quantity) throw (logic_error);
void displayOrderSummary(const Order & order, const Catalog & catalog); 

void main(){
	Catalog catalog; // create a new catalog object

	// try reading the file into the catalog
	try{
		readCatalog(catalog, "Catalog.txt");
	}
	catch (runtime_error e){
		cout << "readCatalog: " << e.what() << endl;
		cout << endl;
	}

	printCatalog(catalog); // print out the catalog

	Order order; // create a new order object

	// try adding some items to the order
	try{
		addItem(order, catalog, "4123RED", 6);
		addItem(order, catalog, "576361B", 10);
		addItem(order, catalog, "93456D", 1);
	}
	catch (logic_error e){
		cout << "addItem: " << e.what() << endl;
	}

	displayOrderItems(order, catalog); // display all the items in the order

	// try removing some items from the order
	try{
		removeItem(order, "576361B", 2);
		removeItem(order, "93456D", 1);
	}
	catch (logic_error e){
		cout << "removeItem: " << e.what() << endl;
	}

	displayOrderItems(order, catalog); // display all the items in the order again
	displayOrderSummary(order, catalog); // display the order summary
}

// reads the input file and creates the catalog; throws a runtime_error if the file cannot be opened
void readCatalog(Catalog & catalog, const string & fileName) throw(runtime_error){
	ifstream infile;
	infile.open(fileName);
	if (!infile.is_open()){
		throw runtime_error("File could not be opened");
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

// prints the SKU, description, price, and weight of every item in the catalog
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
	cout << endl;
}

// finds a single item by SKU and returns the details as a struct; returns a dummy struct with the description "Item not found", price 0.00, and weight 0.00 if the SKU is not in the catalog
ItemInfo getItemData(const Catalog & catalog, const string & sku){
	ItemInfo item;
	Catalog::const_iterator iterator = catalog.find(sku);
	if (iterator != catalog.end()){
		
		item = ItemInfo(iterator->second.description, iterator->second.price, iterator->second.weight);
	}
	else{
		item = ItemInfo();
	}
	return item;
}

// Lists the SKU, description, and quantity of each type of order item
void displayOrderItems(const Order & order, const Catalog & catalog){
	cout << setw(10) << left << "SKU";
	cout << setw(55) << left << "Description";
	cout << setw(12) << left << "Quantity";
	cout << endl;
	cout << setfill('=') << setw(80) << "=" << endl;
	cout << setfill(' ');

	for (Order::const_iterator iterator = order.begin(); iterator != order.end(); iterator++) {
		ItemInfo item = getItemData(catalog, iterator->first);
		cout << setw(10) << left << iterator->first;
		cout << setw(55) << left << item.description;
		cout << setw(12) << fixed << setprecision(2) << left << iterator->second;
		cout << endl;
	}
	cout << endl;
}

// adds item(s) to the order; throws a logic_error if the item cannot be found in the catalog
void addItem(Order & order, const Catalog & catalog, const string & sku, int quantity) throw (logic_error){
	ItemInfo item = getItemData(catalog, sku);
	if (item.description.compare("Item not found") != 0){
		Order::iterator iterator = order.find(sku);
		if (iterator != order.end()){
			iterator->second += quantity;
		}
		else{
			order.insert(make_pair(sku, quantity));
		}
	}
	else{
		throw logic_error("Item not found");
	}
}

// removes items(s) from the order; throws a logic_error if the item cannot be found in the order
void removeItem(Order & order, const string & sku, int quantity) throw (logic_error){
	Order::iterator iterator = order.find(sku);
	if (iterator != order.end()){
		if (quantity < iterator->second){
			iterator->second -= quantity;
		}
		else{
			order.erase(sku);
		}
	}
	else{
		throw logic_error("Item not found");
	}

}

// displays the number of unique item types, the total number of items, the total cost, and the total shipping weight
void displayOrderSummary(const Order & order, const Catalog & catalog){
	int totalQuantity = 0;
	int distinctTypes = 0;
	double totalCost = 0;
	double totalWeight = 0;

	for (Order::const_iterator iterator = order.begin(); iterator != order.end(); iterator++) {
		ItemInfo item = getItemData(catalog, iterator->first);
		totalQuantity += iterator->second;
		distinctTypes++;
		totalCost += (item.price * iterator->second);
		totalWeight += (item.weight * iterator->second);
	}

	cout << setw(30) << left << "Order Summary";
	cout << endl;
	cout << setfill('=') << setw(80) << "=" << endl;
	cout << setfill(' ');

	cout << setw(30) << left << "Distinct Item Types: " << distinctTypes << endl;
	cout << setw(30) << left << "Total number of items: " << totalQuantity << endl;
	cout << setw(30) << fixed << "Total Cost: " << setprecision(2) << totalCost << endl;
	cout << setw(30) << fixed << "Total Weight: " << setprecision(1) << totalWeight << endl;
	cout << endl;
}


