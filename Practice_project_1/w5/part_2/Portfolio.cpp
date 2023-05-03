/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------
Workshop 5 part 2
Name: Juan Pablo Martinez Carett
Module: Porfolio
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:19/02/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Portfolio.h"

using namespace std;
namespace sdds
{
	Portfolio::Portfolio() {
		emptyPortfolio();
	}
	void Portfolio::emptyPortfolio()
	{
		m_value = 0;
		m_stock[0] = 0;
		m_type = 'E';
	}
	Portfolio::Portfolio(double value, const char* stock, char type) {
		emptyPortfolio();
		if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
			m_value = value;
			m_type = type;
			strcpy(m_stock, stock);
		}
	}

	void Portfolio::dispPortfolio() const {
		cout << " ";
		cout.width(10);
		cout << (const char*)(*this);
		cout << " | ";
		cout << "Value: ";
		cout.width(10);
		cout << double(*this);
		cout << " | ";
		cout << " Type: ";
		cout << char(*this);
	}
	std::ostream& Portfolio::display() const {

		if (~*this) {
			cout << " Portfolio  |  Bad-NG |";
			dispPortfolio();
		}
		else if (*this) {
			cout << " Portfolio  |  Active |";
			dispPortfolio();

		}
		else {
			cout << " Portfolio  |  EMPTY  |";
			dispPortfolio();
		}
		return cout;
	}

	Portfolio::operator double() const
	{
		return m_value;
	}

	Portfolio::operator const char* () const
	{
		return this->m_stock;
	}

	Portfolio::operator const char() const
	{
		return m_type;
	}

	Portfolio::operator bool() const
	{
		bool flag = false;
		if ((this->m_type == 'G') || (this->m_type == 'V') || (this->m_type == 'I'))
		{
			flag = true;
		}
		return flag;
	}
	Portfolio& Portfolio::operator+=(const double value)
	{
		if (((this->operator bool())) && (value > 0))
		{
			this->m_value += value;
			// do nothing
		}
		else
		{
			
		}
		return *this;
		// TODO: insert return statement here
	}
	Portfolio& Portfolio::operator-=(const double value)
	{

		if ((this->operator bool()) && (value > 0))
		{
			this->m_value -= value;
			// do nothing
		}
		else
		{
			
		}
		return *this;

	}
	bool Portfolio::operator~() const
	{
		bool flag = false;
		if (this->m_value < 0)
		{
			flag = true;
		}
		return flag;
	}
	Portfolio& Portfolio::operator<<(Portfolio& right_por)
	{
		if ((this->operator bool())&&(right_por.operator bool()))
		{
			this->m_value += right_por.m_value;
			right_por.m_value = 0;
			right_por.emptyPortfolio();
		}
		return *this;
		// TODO: insert return statement here
	}
	Portfolio& Portfolio::operator>>(Portfolio& right_por)
	{
		if ((this->operator bool()) && (right_por.operator bool()))
		{
			right_por.m_value += this->m_value;
			this->m_value = 0;
			this->emptyPortfolio();
		}
		return right_por;
		// TODO: insert return statement here
	}
	double operator+(const Portfolio& one, const Portfolio& two)
	{
		double value = 0;
		value = one.m_value + two.m_value;
		return value;
	}
	double operator+=(double& n_val,const Portfolio& p)
	{
		n_val += p.m_value;
		return n_val;
	}
}