/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:09/04/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Item.h"
#include "Status.h"
#include "Utils.h"
namespace sdds
{
	bool Item::linear() const
	{
		return m_linear;
	}
	int Item::operator-=(int qty)
	{
		m_qty -= qty;
		return m_qty;
	}

	int Item::operator+=(int qty)
	{
		m_qty += qty;
		return m_qty;
	}

	void Item::linear(bool isLinear)
	{
		m_linear = isLinear;
	}

	bool Item::operator==(int sku) const
	{
		bool flag = false;

		if (m_sku == sku)
		{
			flag = true;
		}
		return flag;
	}
	
	bool Item::operator==(const char* description) const
	{
		bool flag = false;
		char* tmp;
		tmp = strstr(m_description, description);
		if (tmp != NULL)
		{
			flag = true;
		}
		return flag;
	}

	std::ofstream& Item::save(std::ofstream& ofstr) const
	{
		if (i_status)
		{
			ofstr << m_sku << '\t';
			ofstr << m_description << '\t';
			ofstr << m_qty << '\t';
			ofstr << m_qtyNeeded << '\t';
			ofstr << m_price;
		}
		return ofstr;
	}

	std::ifstream& Item::load(std::ifstream& ifstr)
	{
		char support[2000];
		
		if (ifstr)
		{
			ifstr >> m_sku;
			ifstr.ignore();
			ifstr.getline(support, 1000, '\t');
			ut.alocpy(m_description, support);
			ifstr >> m_qty;
			ifstr.ignore();
			ifstr >> m_qtyNeeded;
			ifstr.ignore();
			ifstr >> m_price;
			ifstr.ignore();
		}
		if (!ifstr)
		{
			i_status = "Input file stream read failed!";
		}
		return ifstr;
	}

	int Item::readSku(std::istream& istr)
	{
		int value = ut.getint(40000, 99999, "SKU: ", "Invalid Integer");
		return value;
	}

	std::ostream& Item::display(std::ostream& ostr) const
	{
		if ((i_status)&&(m_description!=nullptr))
		{
			if (linear())
			{
				char support[1000];
				strcpy(support, m_description);
				ostr << m_sku;
				ostr << " | ";
				support[35] = '\0';
				ostr << support;
				ostr.width(38 - strlen(support));
				ostr.fill(' ');
				ostr << " | ";
				ostr.width(4);
				ostr << m_qty << " | ";
				ostr.width(4);
				ostr << m_qtyNeeded << " | ";
				ostr.width(7);
				ostr << m_price << " |";
				}
			else
			{
				ostr << "AMA Item:" << std::endl;
				ostr << m_sku << ": " << m_description << std::endl;
				ostr << "Quantity Needed: " << m_qtyNeeded << std::endl;
				ostr << "Quantity Available: " << m_qty << std::endl;
				ostr << "Unit Price: $" << std::fixed << std::setprecision(2) << m_price << std::endl;
				ostr << "Needed Purchase Fund: $" << (m_qtyNeeded - m_qty) * m_price << std::endl;
			}
		}
		else
		{
			ostr << m_description << std::endl;
		}
		return ostr;
	}

	std::istream& Item::read(std::istream& istr)
	{
		char support[1000];
		i_status.clear();
		std::cout << "AMA Item:" << std::endl;
		m_sku = readSku(istr);
		std::cout << "Description: ";
		istr.ignore();
		istr.getline(support, 9999, '\n');
		ut.alocpy(m_description, support);
		m_qtyNeeded = ut.getint(1, 9999, "Quantity Needed: ", "Invalid Integer");
		m_qty = ut.getint(0, m_qtyNeeded, "Quantity On Hand: ", "Invalid Integer");
		m_price = ut.getdouble(0.00, 9999.00, "Unit Price: $", "Invalid number");
		if (istr.bad())
		{
			i_status = "Console entry failed!";
		}
		return istr;
	}
	int Item::qty() const
	{
		return m_qty;
	}

	Item::operator double() const
	{
		return  m_price;
	}

	Item::operator bool() const
	{
		return (m_description);
	}

	Item::Item()
	{
		
		m_description = nullptr;
	}

	Item::~Item()
	{
		delete[] m_description;
		m_description = nullptr;
		clear();

	}

	Item::Item(const Item& right)
	{
		*this = right;
	}

	Item& Item::operator=(const Item& It)
	{
		if (this!=&It)
		{
			if (It.m_description != nullptr) {
				ut.alocpy(m_description, It.m_description);
				m_price = It.m_price;
				m_qty = It.m_qty;
				m_qtyNeeded = It.qtyNeeded();
				m_linear = It.m_linear;
				m_sku = It.m_sku;
				// check this at the end
				i_status = It.i_status;
			}
		}
		return *this;
	}

	int Item::qtyNeeded() const
	{
		return m_qtyNeeded;
	}
}
