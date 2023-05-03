/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:09/04/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef PERISHABLE_H
#define PERISHABLE_H
#include "Date.h"
#include "Item.h"

namespace sdds
{
	class Perishable : public Item 
	{
		Date m_expiry; // by deault 
		char* m_instruction{};
	public:
		//Constructor
		Perishable() { m_instruction = nullptr; };// ok
		// copy constructor and overload of the =
		Perishable(const Perishable& per);

		Perishable& operator=(const Perishable& per);
		//query
		Date expiry() const;
		//deconstructor
		~Perishable() { delete[] m_instruction; m_instruction = nullptr; }

		//virtual overrides
		int readSku(std::istream& istr);

		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);//ok
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);//
	};
}

#endif // !STATUS_H