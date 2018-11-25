//Created by Callum King for the UNiDAYS Discounts Programming Challenge for the 12 month placement (2019-20)
#include <iostream>
#include <algorithm>
#include <map>
#include <regex>
#include <sstream>
#include "UnidaysDiscountChallenge.h"
#include "Item.h"
#include "Functions.h"

using namespace std;

void main() {

	Item itemOne("A", 8.00);
	Item itemTwo("B", 12.00);
	Item itemThree("C", 4.00);
	Item itemFour("D", 7.00);
	Item itemFive("E", 5.00);
	
	Item pricingRules[5] = { itemOne, itemTwo, itemThree, itemFour, itemFive };
	Item *PricingRulesPtr = pricingRules;

	UnidaysDiscountChallenge udc(PricingRulesPtr);

	cout << "Welcome to the UNiDAYS Discounts Program" << endl << endl << "It has all been written by Callum King at the University of Lincoln" << endl << endl;

	system("pause");
	system("CLS");
	
	string userInput = "";
	outputShop(); //function to output the shop
	cout << "Please enter the items you would like to buy below in a consecutive string. Example = 'AABBCDDE' and then press ENTER." << endl;
	cin >> userInput; //gets user input of items
	transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower); //puts all users input to lowercase
	for (string::iterator it = userInput.begin(); it != userInput.end(); ++it) { //iterates through each letter and adds it to basket
		int temp = itemNameToNum(*it);
		char input = *it;
		bool valid = testLetter(input);

		if (valid == true) { //if user input is [a-e] then add it to basket
			PricingRulesPtr = &pricingRules[temp];
			udc.AddToBasket(*PricingRulesPtr);
		}
	}
	system("CLS");
	map<char, int> itemCount = outputBasket(udc);
	cout << "Type X and press ENTER to add any discounts and receive your total price." << endl;
	char hold;
	cin >> hold;
	system("CLS");

	udc.CalculateTotalPrice(itemCount); //get total price and output
		

	cout << endl << endl;
	system("pause");
}