#include <string>
#include <algorithm>
#include <cmath>
#include "UnidaysDiscountChallenge.h"
#include "Item.h"

using namespace std;

UnidaysDiscountChallenge::UnidaysDiscountChallenge() 
{

}

UnidaysDiscountChallenge::UnidaysDiscountChallenge(Item *&PR)
{
	for (int i = 0; i < 5; i++)
	{
		items[i] = *PR;
		*PR++;
	}
}

void UnidaysDiscountChallenge::AddToBasket(Item it)
{
	basket.push_back(it);
}

double UnidaysDiscountChallenge::CalculateTotalPrice(map<char, int> IC)
{
	cout << "The basket contains and costs the following WITH discouns applied: " << endl << endl
		<< "ITEM        -    PRICE" << endl;

	itemCount = IC;
	if (itemCount.count('A') > 0)
	{
		itemTotalCost['A'] = itemCount['A'] * 8; //No discount so just times the amount by the price
		cout << "A x " << itemCount['A'] << "       -    \x9C" << itemTotalCost['A'] << ".00" << endl;
		finalTotal += itemTotalCost['A'];
	}
	if (itemCount.count('B') > 0)
	{
		if (fmod(itemCount['B'], 2) == 1) { itemTotalCost['B'] = (((itemCount['B'] - 1) / 2) * 20) + 12; } //Using modular, finds if there is an odd item, if so, take it away, work out the discount, add it after
		else {
			itemTotalCost['B'] = (itemCount['B'] / 2) * 20;
		}

		cout << "B x " << itemCount['B'] << "       -    \x9C" << itemTotalCost['B'] << ".00" << endl;
		finalTotal += itemTotalCost['B'];
	}
	if (itemCount.count('C') > 0)
	{
		if (fmod(itemCount['C'], 3) > 0)
		{
			if (fmod(itemCount['C'], 3) == 1) { itemTotalCost['C'] = (((itemCount['C'] - 1) / 3) * 10) + 4; }
			if (fmod(itemCount['C'], 3) == 2) { itemTotalCost['C'] = (((itemCount['C'] - 2) / 3) * 10) + 8; }
		}
		else {
			if (itemCount['C'] < 3) { itemTotalCost['C'] = itemCount['C'] * 4; }
			else {
				itemTotalCost['C'] = (itemCount['C'] / 3) * 10;
			}
		}

		cout << "C x " << itemCount['C'] << "       -    \x9C" << itemTotalCost['C'] << ".00" << endl;
		finalTotal += itemTotalCost['C'];
	}
	if (itemCount.count('D') > 0)
	{
		if (fmod(itemCount['D'], 2) == 1) { itemTotalCost['D'] = (((itemCount['D'] - 1) / 2) * 7) + 7; }
		else {
			itemTotalCost['D'] = (itemCount['D'] / 2) * 7;
		}

		cout << "D x " << itemCount['D'] << "       -    \x9C" << itemTotalCost['D'] << ".00" << endl;
		finalTotal += itemTotalCost['D'];
	}
	if (itemCount.count('E') > 0)
	{
		if (fmod(itemCount['E'], 3) > 0)
		{
			if (fmod(itemCount['E'], 3) == 1) { itemTotalCost['E'] = (((itemCount['E'] - 1) / 3) * 10) + 5; }
			if (fmod(itemCount['E'], 3) == 2) { itemTotalCost['E'] = (((itemCount['E'] - 2) / 3) * 10) + 10; }
		}
		else {
			if (itemCount['E'] < 3) { itemTotalCost['E'] = itemCount['E'] * 5; }
			else {
				itemTotalCost['E'] = (itemCount['E'] / 3) * 10;
			}
		}

		cout << "E x " << itemCount['E'] << "       -    \x9C" << itemTotalCost['E'] << ".00" << endl;
		finalTotal += itemTotalCost['E'];
	}
	
	cout << endl << "The cost of your basket after discounts is a total of \x9C" << finalTotal << ".00" << endl;
	if (finalTotal < 50) //If price is less than 50, add delivery charge of 7
	{
		finalTotal += 7;
		cout << "A delivery fee of \x9C" << "7 has been added as the total is under \x9C" << "50" << endl;
	};

	cout << "Grand total: \x9C" << finalTotal << endl;

	return finalTotal;
}

string UnidaysDiscountChallenge::getItemName(int a)
{
	Item temp = basket[a];
	return temp.getItemName();
}

double UnidaysDiscountChallenge::getItemPrice(int itemNo)
{
	Item temp = items[itemNo];
	return temp.getItemPrice();
}

void UnidaysDiscountChallenge::setItemCount(map<char, int> IC)
{
	itemCount = IC;
}

map<char, int> UnidaysDiscountChallenge::getItemCount()
{
	return itemCount;
}

void UnidaysDiscountChallenge::setItemTotalCost(map<char, double> ITC)
{
	itemTotalCost = ITC;
}

map<char, double> UnidaysDiscountChallenge::getItemTotalCost()
{
	return itemTotalCost;
}

void UnidaysDiscountChallenge::setTotal(double t)
{
	total = t;
}

void UnidaysDiscountChallenge::addTotal(double t)
{
	total += t;
}

double UnidaysDiscountChallenge::getTotal()
{
	return total;
}

vector<Item> UnidaysDiscountChallenge::retrieveBasket()
{
	return basket;
}