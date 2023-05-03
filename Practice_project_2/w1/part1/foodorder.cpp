// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:01/16/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "foodorder.h"


using namespace std;
double g_taxrate;
double g_dailydiscount;
namespace sdds {

	std::istream& FoodOrder::read(std::istream& in)
	{
		char status{};
		if (in.good()) {
			in.get(m_customerOrder, 10, ',');
			in.ignore();
			in.get(m_foodDescription, 25, ',');
			in.ignore();
			in >> priceFood;
			in.ignore();
			in.get(status);
			if (status == 'Y')
			{
				specialDay = true;
			}
			else
				specialDay = false;
		}
		else {
			//do nothing
		}
		return in;
	}

	void FoodOrder::display() const {
		//COUNTER. Name          |Order Description        |Price w/Tax |Special Price
		double fprice = 0;
		static int counter;
		if (counter == 0)
			counter++;
		else
		{
			counter++;
		}
		if (m_customerOrder[0] == '\0')
		{
			cout << counter << ". No Order\n";
		}
		else {
			cout.width(2);
			cout.setf(ios::left);
			cout << counter;
			cout << ". ";
			cout.width(10);
			cout << m_customerOrder << "|";
			cout.width(25);
			cout << m_foodDescription << "|";
			fprice = (priceFood * (1 + g_taxrate));
			cout.setf(ios::fixed);
			cout.width(12);
			cout.precision(2);
			cout << fprice << "|";
			cout.unsetf(ios::left);
			if (specialDay)
			{
				cout.width(13);
				cout << (priceFood * (1 + g_taxrate)) - g_dailydiscount;
			}
			cout << "\n";
		}
	}

}