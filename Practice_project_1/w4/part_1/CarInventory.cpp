/* ------------------------------------------------------
Workshop 4 part 1
Name: Juan Pablo Martinez Carett
Module: CarInventory
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:2/10/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CarInventory.h"
#include <iomanip>
using namespace std;
namespace sdds
{
	// constructors
	//default constructor
	CarInventory::CarInventory()
	{
		resetInfo();
	}
	//The other constructor
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
	{

		//	setInfo(type, brand, model, year, code, price);
		if (type != NULL)
		{
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
		}
		else
		{
			resetInfo();
		}
		if (brand != NULL)
		{
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
		}
		else
		{
			resetInfo();
		}
		if (model != NULL)
		{
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
		}
		else
		{
			resetInfo();
		}
		//similarly fro brand, model 
		if (year >= 1990) {
			m_year = year;
		}
		else {
			resetInfo();
		}
		if ((code >= 0) && (code <= 999)) {
			m_code = code;
		}
		else {
			resetInfo();
		}
		if (price > 0) {
			m_price = price;
		}
		else {
			resetInfo();
		}

		//return *this;

	}

	void CarInventory::resetInfo() {

		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}

	void CarInventory::printInfo() const
	{
		int lent = 0;
		cout << "| ";
		cout << this->m_type;
		lent = strlen(m_type);
		cout.width(13 - lent);
		cout << "| ";
		cout << this->m_brand;
		lent = strlen(m_brand);
		cout.width(19 - lent);
		cout << "| ";
		cout << this->m_model;
		lent = strlen(m_model);
		cout.width(19 - lent);

		cout << "| ";
		cout << this->m_year;
		cout.width(4);
		cout << "|  ";
		cout << this->m_code;
		cout.width(3);
		cout << "| ";
		cout.width(9);
		cout.setf(ios::right);
		cout << fixed << setprecision(2);
		cout << this->m_price;
		cout << " |" << endl;

	}

	bool CarInventory::isValid()const //  OK
	{
		bool flag = false;
		if ((m_type) != nullptr) // ok
		{
			if ((m_brand) != nullptr) // ok
			{
				if ((m_model) != nullptr) //ok
				{
					if ((m_year >= 1990))// ok
					{
						if ((m_code) > 000)
						{
							if ((m_code) <= 999)
							{
								if (m_price > 0)
								{
									flag = true;
								}
							}
						}
					}
				}
			}
		}
		return flag;

	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{
		bool flag = false;
		if ((m_brand == car.m_brand) && (m_type == car.m_type) && (m_brand == car.m_brand) && (m_year == car.m_year))
		{
			flag = true;
		}
		return flag;

	}
	bool find_similar(CarInventory car[], const int num_cars)
	{
		bool flag = false;
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {

					flag = true;
				}
			}
		}
		return flag;
	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		this->~CarInventory();
		if (type != NULL)
		{
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			//delete[] this->m_type;
			//m_type = nullptr;
		}
		else
		{
			resetInfo();
		}
		if (brand != NULL)
		{
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
		}
		else
		{
			resetInfo();
		}
		if (model != NULL)
		{
			m_model = new char[strlen(model) + 1];
			strcpy(m_model, model);
		}
		else
		{
			resetInfo();
		}
		//similarly fro brand, model 
		if (year >= 1990) {
			m_year = year;
		}
		else {
			this->~CarInventory();

			//			resetInfo();
		}
		if ((code >= 0) && (code <= 999)) {
			m_code = code;
		}
		else {
			resetInfo();
		}
		if (price > 0) {
			m_price = price;
		}
		else {
			resetInfo();
		}

		return *this;
	}

	CarInventory::~CarInventory()
	{
		delete[] m_brand;
		delete[] m_model;
		delete[] m_type;
		m_brand = nullptr;
		m_model = nullptr;
		m_type = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;

	}
}