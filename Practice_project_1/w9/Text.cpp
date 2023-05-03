/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:30/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <ostream>
#include <istream>
#include <iostream>
#include <cstring>
#include "Text.h"

namespace sdds
{
	const char& Text::operator[](int index) const
	{
		return m_conten[index];
	}



	Text::~Text()
	{
		delete[] m_conten;
		m_conten = nullptr;
	}

	Text::Text(const Text& te)
	{
		*this = te;
	}

	istream& Text::read(istream& istr)
	{
		int va = getFileLength(istr) + 1;
		delete[] m_conten;
		m_conten = nullptr;
		m_conten = new char[va];

		if (istr)
		{
			istr.getline(m_conten, va, '\0');
		}
		else
		{
			istr.clear();
			m_conten = nullptr;

		}
		return istr;
	}

	ostream& Text::write(ostream& ostr) const
	{

		if (m_conten != nullptr)
		{
			ostr << m_conten;
		}
		return ostr;

	}

	int Text::getFileLength(istream& is)
	{
		int len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, ios::end);
			// let what is the positions (end position = size)
			len = is.tellg();
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}



	Text& Text::operator=(const Text& right)
	{
		if (this != &right)
		{



			if (right.m_conten != nullptr)
			{
				delete[] m_conten;
				m_conten = nullptr;
				m_conten = new char[strlen(right.m_conten) + 1];
				strcpy(m_conten, right.m_conten);

			}
		}
		return *this;
	}

	std::ostream& operator << (std::ostream& ost, const Text& te)
	{
		te.write(ost);
		return ost;

	}

	std::istream& operator >> (std::istream& ist, Text& te)
	{
		te.read(ist);
		return  ist;
	}


}
