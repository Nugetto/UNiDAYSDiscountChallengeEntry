#include <iostream>
#include <map>
#include "UnidaysDiscountChallenge.h"

using namespace std;

void outputShop()
{
	cout << "The items that are available are the following: " << endl << endl
		<< "ITEM    -    PRICE    -    DISCOUNT" << endl << endl
		<< "A       -    \x9C" << "8.00    -    N/A" << endl
		<< "B       -    \x9C" << "12.00   -    2 FOR \x9C" << "20.00" << endl
		<< "C       -    \x9C" << "4.00    -    3 FOR \x9C" << "10.00" << endl
		<< "D       -    \x9C" << "7.00    -    BUY 1 GET 1 FREE" << endl
		<< "E       -    \x9C" << "5.00    -    3 FOR THE PRICE OF 2" << endl << endl;
}

int itemNameToNum(char item)
{
	switch (item) 
	{
	case 'a':
		return 0;
	case 'b':
		return 1;
	case 'c':
		return 2;
	case 'd':
		return 3;
	case 'e':
		return 4;
	}
}

bool testLetter(char input)
{
	switch (input)
	{
	case 'a':
		return true;
	case 'b':
		return true;
	case 'c':
		return true;
	case 'd':
		return true;
	case 'e':
		return true;
	default:
		return false;
	}
}

map<char, int> outputBasket(UnidaysDiscountChallenge udc)
{
	double total = 0;
	vector<Item> basket = udc.retrieveBasket();
	cout << "The basket currently contains the following: " << endl << endl
		 << "ITEM        -    PRICE" << endl;

	map<char, int> itemCount = udc.getItemCount();
	map<char, double> itemTotalCost = udc.getItemTotalCost();

	for (vector<Item>::iterator it = basket.begin(); it != basket.end(); ++it) {

		Item tempItem = *it;
		string tempName = tempItem.getItemName();
		itemCount[tempName[0]] += 1;
	}

	if (itemCount.count('A') > 0)
	{
		double itemTotal = (udc.getItemPrice(0) * itemCount['A']);
		cout << "A x " << itemCount['A'] << "       -    \x9C" << itemTotal << ".00" << endl;
		total += itemTotal;
		itemTotalCost['A'] = itemTotal;
	}
	if (itemCount.count('B') > 0)
	{
		double itemTotal = (udc.getItemPrice(1) * itemCount['B']);
		cout << "B x " << itemCount['B'] << "       -    \x9C" << itemTotal << ".00" << endl;
		total += itemTotal;
		itemTotalCost['B'] = itemTotal;
	}
	if (itemCount.count('C') > 0)
	{
		double itemTotal = (udc.getItemPrice(2) * itemCount['C']);
		cout << "C x " << itemCount['C'] << "       -    \x9C" << itemTotal << ".00" << endl;
		total += itemTotal;
		itemTotalCost['C'] = itemTotal;
	}
	if (itemCount.count('D') > 0)
	{
		double itemTotal = (udc.getItemPrice(3) * itemCount['D']);
		cout << "D x " << itemCount['D'] << "       -    \x9C" << itemTotal << ".00" << endl;
		total += itemTotal;
		itemTotalCost['D'] = itemTotal;
	}
	if (itemCount.count('E') > 0)
	{
		double itemTotal = (udc.getItemPrice(4) * itemCount['E']);
		cout << "E x " << itemCount['E'] << "       -    \x9C" << itemTotal << ".00" << endl;
		total += itemTotal;
		itemTotalCost['E'] = itemTotal;
	}

	cout << endl << "Total without discount and without delivery fee is: \x9C" << total << ".00" << endl;

	return itemCount;
}