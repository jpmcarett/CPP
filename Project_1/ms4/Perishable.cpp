/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:07/04/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include <fstream>
#include <cstring>
#include <iostream>
#include "Perishable.h"
#include "Utils.h"
using  namespace  std;
namespace sdds
{
	Perishable::Perishable(const Perishable& per) :Item(per)
	{
		*this = per;
	}

	Perishable& Perishable::operator=(const Perishable& per)
	{
		if (this != &per)
		{
			if (per.m_instruction != nullptr)
			{
				ut.alocpy(m_instruction, per.m_instruction);
				this->m_expiry = per.m_expiry;
			}
			Item::operator=(per);
		}
		return  *this;
	}

	Date Perishable::expiry() const
	{
		
		return  m_expiry;
	}

	int Perishable::readSku(istream& istr)
	{
		int value = ut.getint(10000, 39999, "SKU: ", "Invalid Integer");
		return value;
	}
	ofstream& Perishable::save(ofstream& ofstr) const
	{
		if (i_status)
		{
			Date second;
			Item::save(ofstr);
			ofstr << '\t';
			if ((m_instruction != nullptr)&& (strlen(m_instruction) > 0))
			{
				ofstr << m_instruction;
			}
			ofstr << '\t';
			second = m_expiry;
			second.formatted(false);
			ofstr << second;
		}
		return ofstr;
	}
	ifstream& Perishable::load(ifstream& ifstr)
	{
		char support[2000];
		Item::load(ifstr);
		ifstr.getline(support, 1000, '\t');
		ut.alocpy(m_instruction, support);
		ifstr >> m_expiry;
		ifstr.ignore();
		if (ifstr.bad())
		{
			i_status = "Input file stream read failed!";
		}
		return  ifstr;

	}
	ostream& Perishable::display(ostream& ostr) const
	{
		if (i_status)
		{
			if (linear())
			{
				Item::display(ostr);

				if ((m_instruction != nullptr)&&(strlen(m_instruction) >0))
				{
					ostr << "*";
				}
				else
				{
					ostr << " ";
				}
				ostr << m_expiry;
			}
			else
			{
				ostr << "Perishable ";
				Item::display(ostr);
				ostr << "Expiry date: ";
				ostr << m_expiry << endl;
				if ((m_instruction != nullptr)&&(strlen(m_instruction)>0))
				{
					ostr << "Handling Instructions: ";
					ostr << m_instruction<<std::endl;
					
				}
			}
		}
		else
		{
			ostr << i_status << endl;
		}
		return ostr;
	}
	istream& Perishable::read(istream& istr)
	{
		char hope[1000];
		Item::read(istr);
		cout << "Expiry date (YYMMDD): ";
		istr >> m_expiry;
		cout << "Handling Instructions, ENTER to skip: ";
		istr.ignore();
		//istr.get();
		if (istr.peek() != '\n')
		{
			istr.getline(hope, 1000, '\n');
			ut.alocpy(m_instruction, hope);
		}
		if (istr.fail())
		{
			Item::i_status = "Perishable console date entry failed!";
		}
		return istr;
	}
}
