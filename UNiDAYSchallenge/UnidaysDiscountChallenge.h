#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Item.h"

class UnidaysDiscountChallenge {

	double finalTotal;
	double total;
	double deliveryCharge;
	vector<Item> basket;
	Item items[5];
	map<char, int> itemCount;
	map<char, double> itemTotalCost;


public:
	UnidaysDiscountChallenge();
	UnidaysDiscountChallenge(Item *&PR);
	void AddToBasket(Item it);
	double CalculateTotalPrice(map<char, int> IC);
	string getItemName(int a);
	double getItemPrice(int itemNo);
	void setItemCount(map<char, int> IC);
	map<char, int> getItemCount();
	void setItemTotalCost(map<char, double> ITC);
	map<char, double> getItemTotalCost();
	void setTotal(double t);
	void addTotal(double t);
	double getTotal();
	vector<Item> retrieveBasket();
};