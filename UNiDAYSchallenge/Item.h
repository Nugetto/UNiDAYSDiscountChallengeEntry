#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item {
private:
	string item;
	double price;

public:
	Item();
	Item(string it, double pr);
	void setItemName(string it);
	string getItemName();
	void setItemPrice(double pr);
	double getItemPrice();
};