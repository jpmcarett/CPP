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
#include <cstring>
#include "HtmlText.h"

namespace sdds
{

	HtmlText::HtmlText(const char* title)
	{
		m_title = nullptr;
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);


	}
	HtmlText::HtmlText(const HtmlText& ht)
	{
		*this = ht;
	}
	ostream& HtmlText::write(ostream& ostr) const
	{
		bool flag = false;
		char value = 'p';
		int hope = 0;

		ostr << "<html>" << "<head>" << "<title>";
		if (m_title != nullptr)
		{
			ostr << m_title;
		}
		else
		{
			ostr << "No Title";
		}

		ostr << "</title>" << "</head>" << endl;
		ostr << "<body>" << endl;

		if (m_title != nullptr)
		{
			ostr << "<h1>" << m_title << "</h1>" << endl;
		}

		while (value != '\0')
		{

			value = this->operator[](hope);
			switch (value)
			{
			case ' ': // space case
				if (flag == true)
				{
					ostr << "&nbsp;";
				}
				else
				{
					flag = true;
					ostr << " ";
				}
				break;
			case '<': //
				flag = false;
				ostr << "&lt;";
				break;
			case '>': // 
				flag = false;
				ostr << "&gt;";
				break;

			case '\n': // 
				ostr << "<br />\n";
				flag = false;
				break;
			case '\0':

				ostr << "</body>" << endl;
				ostr << "</html>";

				break;
			default: // 
				flag = false;
				ostr << value;
				break;

			}
			hope++;
		}
		return  ostr;
	}
	HtmlText& HtmlText::operator=(const HtmlText& right2)
	{
		if (this != &right2)
		{


			if ((m_title != right2.m_title) && (this != &right2))
			{
				delete[] m_title;
				m_title = nullptr;
				m_title = new char[strlen(right2.m_title) + 1];
				strcpy(m_title, right2.m_title);
				(Text&)*this = right2;

			}
		}
		return *this;
	}
	HtmlText::~HtmlText()
	{
		delete[] m_title;
		m_title = nullptr;

	}
}