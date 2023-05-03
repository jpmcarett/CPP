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
#ifndef CARINVENTORY_H // replace with relevant names
#define CARINVENTORY_H

namespace sdds
{
	class CarInventory
	{
		// be default
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		//
		void resetInfo();

	public:
		//Default constructor
		CarInventory();
		// The other constructor
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);

		// function
		bool isValid() const;
		void printInfo() const;
		bool isSimilarTo(const CarInventory& car) const;
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		~CarInventory();
	};

	bool find_similar(CarInventory car[], const int num_cars);
}
#endif