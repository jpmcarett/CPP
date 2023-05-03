/* ------------------------------------------------------
Workshop 6 part 1
Name: Juan Pablo Martinez Carett
Module: Train
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:4/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <istream>
#include <cstring>
#include "HealthCard.h"
using namespace std;
namespace sdds {
	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
	{
		
		bool flag = false;
		if ((name != nullptr) && (number > 999999999) && (number < 9999999999) && (strlen(vCode)== 2) && (strlen(sNumber) == 9))
		{
			flag = true;
		}
		return flag;
	}
	void HealthCard::setEmpty()
	{
		m_name = nullptr;
		m_number = 0;
		m_vCode[0] = 0;
		m_sNumber[0] = 0;

	}

	void HealthCard::allocateAndCopy(const char* name)
	{
		delete [] m_name;
		m_name = nullptr;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	void HealthCard::extractChar(istream& istr, char ch) const
	{
		char check;
		check = istr.peek();
		if (check == ch) {
			istr.ignore();
		}
		else {

			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}

	}

	ostream& HealthCard::printIDInfo(ostream& ostr) const
	{
		ostr << m_number << "-" << m_vCode << ", " << m_sNumber;

		return ostr;
	}

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		if (validID(name, number, vCode, sNumber))
		{
			allocateAndCopy(name);
			m_number = number;
			strncpy(m_vCode, vCode,3);
			strncpy(m_sNumber, sNumber,10);
		}
		else
		{
			delete [] m_name;
			setEmpty();
		}
	}

	HealthCard::HealthCard(const HealthCard& hc)
	{
			if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber))
			{
				allocateAndCopy(hc.m_name);
				this->m_number = hc.m_number;
				strcpy(this->m_vCode, hc.m_vCode);
				strcpy(this->m_sNumber, hc.m_sNumber);
				
				
			}
	}

	HealthCard::~HealthCard()
	{
		delete[] m_name;
		m_name = nullptr;
		m_number = 0;
		m_vCode[0] = '\0';
		m_sNumber[0] = '\0';
	}

	HealthCard::operator bool() const
	{
		bool flag = false;
		if (m_name != nullptr) {
			flag = true;
		}
		return flag;
	}

	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		set(name, number, vCode, sNumber);
	}

	ostream& HealthCard::print(ostream& ostr, bool toFile) const
	{

		if (validID(m_name, m_number, m_vCode, m_sNumber)) {
			if (toFile )
			{
				ostr << m_name << ",";
				printIDInfo(ostr) << endl;
			}
			else
			{
				ostr.setf(ios::left);
				ostr.width(50);
				ostr.fill('.');
				ostr << m_name;
				printIDInfo(ostr);
			}
		}
		return ostr;
	}

	HealthCard& HealthCard::operator=(const HealthCard& hc)
	{
		if (this != &hc)
		{

			if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber))
			{
				set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
			}
			else
			{
				delete [] m_name;
				m_name = nullptr;
			}
		}
		return *this;
	}

	std::istream& HealthCard::read(std::istream& istr)
	{

		char name[MaxNameLength];
		long long m_num;
		char m_vCo[3];
		char m_sNum[10];
		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> m_num;
		extractChar(istr, '-');
		istr.get(m_vCo, 3, ',');
		extractChar(istr, ',');
		istr.get(m_sNum, 10, '\n');
		if (!(istr.fail()))
		{
			set(name, m_num, m_vCo, m_sNum);
		}
		else
		{
			this->setEmpty();
		}
		istr.clear();
		istr.ignore(800, '\n');
		return istr;

		// TODO: insert return statement here
	}
	std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc)
	{
		if (hc)
		{
			hc.print(ostr, false);
		}
		else
		{
			cout << "Invalid Health Card Record";
		}
		return ostr;

		// TODO: insert return statement here
	}

	std::istream& operator>>(std::istream& istr, HealthCard& hc)
	{
		return hc.read(istr);
		// TODO: insert return statement here
	}
}
