/* ------------------------------------------------------
Workshop 8 part 1
Name: Juan Pablo Martinez Carett
Module: LblShape
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:26/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <cstring>
namespace sdds{
char* LblShape::label() const
{
	return m_label;
}
LblShape::LblShape()
{
	m_label = nullptr;
}
LblShape::LblShape(const char* s_label)
{
	delete [] m_label;
	m_label = nullptr;
	if (s_label!=nullptr)
	{
		m_label = new char[strlen(s_label) + 1];
		strcpy(m_label, s_label);
	}
}

void LblShape::getSpecs(istream&  ist)
{
	delete[] m_label;
	m_label = nullptr;
	char support[1000];
	ist.getline(support,50,',');
	m_label = new char[strlen(support) + 1];
	strcpy(m_label, support);
}
}