#include <iostream>
#include "Item.h"

using namespace std;

Item::Item()
{

}

Item::Item(string it, double pr)
{
	item = it;
	price = pr;
}

void Item::setItemName(string it)
{
	item = it;
}

string Item::getItemName()
{
	return item;
}

void Item::setItemPrice(double pr)
{
	price = pr;
}

double Item::getItemPrice()
{
	return price;
}