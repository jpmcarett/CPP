// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:01/22/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "foodorder.h"


using namespace std;
double g_taxrate;
double g_dailydiscount;
namespace sdds {

	std::istream& FoodOrder::read(std::istream& in)
	{
		char status{};
		std::string description{};
		
		if (in.good()) {
			in.getline(c_order, 10, ',');
			getline(in, description, ',');
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
		if (f_description != nullptr)
		{
			delete[] f_description;
			f_description = nullptr;
		}
		f_description = new char[description.length() + 1];
		strcpy(f_description, description.c_str());
		f_description[description.length()] = '\0';
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
		if (c_order[0] == '\0')
		{
			cout << counter << ". No Order\n";
		}
		else {
			cout.width(2);
			cout.setf(ios::left);
			cout << counter;
			cout << ". ";
			cout.width(10);
			cout << c_order << "|";
			cout.width(25);
			cout << f_description << "|";
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

	FoodOrder& FoodOrder::operator=(const FoodOrder &other)
	{
		if (this!=&other)
		{
			strcpy(c_order, other.c_order);
			priceFood = other.priceFood;
			specialDay = other.specialDay;

			if (f_description!=nullptr)
			{
				cout << &f_description << "   " << endl;
				delete[] f_description;
				f_description = nullptr;
			}
			if (other.f_description!=nullptr && other.f_description[0]!='\0')
			{
				int size_po = std::strlen(other.f_description);
				f_description = new char[size_po + 1];
				std::strcpy(f_description, other.f_description);
				f_description[size_po] = '\0';
			}
		}
		return *this;
	}
	FoodOrder::FoodOrder(const FoodOrder& copy)
	{
			*this = copy;
	}
}
