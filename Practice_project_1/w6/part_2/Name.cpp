
/* ------------------------------------------------------
Workshop 6 part 2
Name: Juan Pablo Martinez Carett
Module: Name
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:10/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <istream>
#include "Name.h"

namespace sdds {
	void Name::setEmpty()// you could delete this function at the end
	{
		delete[] f_name;
		f_name = nullptr;
		delete[] m_name;
		m_name = nullptr;
		delete[] l_name;
		l_name = nullptr;
	}

	Name::Name(const char* fname, const char* mname, const char* lname)
	{
		if ((lname != nullptr) )
		{
			set(lname, 3);
		}
		if ((mname != nullptr) )
		{
			set(mname, 2);
		}
		if ((fname != nullptr))
		{
			set(fname, 1);

		}
		else 
		{
			this->setEmpty();
		}

	}

	Name::operator bool() const
	{
		bool flag = true;
		if ((m_name == nullptr))
		{
			if ((l_name == nullptr))
			{
				if ((f_name == nullptr) )
				{
					flag = false;
				}
			}
		}
		return flag;
	}

	Name::Name(const Name& nm)
	{
		if (nm.f_name!=nullptr)
		{
			f_name = new char[strlen(nm.f_name) + 1];
			strcpy(f_name, nm.f_name);

		}
		if (nm.m_name!=nullptr)
		{
			m_name = new char[strlen(nm.m_name) + 1];
			strcpy(m_name, nm.m_name);

		}
		if (nm.l_name!=nullptr)
		{
			l_name = new char[strlen(nm.l_name) + 1];
			strcpy(l_name, nm.l_name);
		}
	}

	void Name::set(const char* na, int number)
	{
		//Reduce this code
		if (number == 1) {
			delete[] f_name;
			f_name = nullptr;
			f_name = new char[strlen(na)+1];
			strcpy(f_name, na);
		}
		if (number == 2)
		{
			delete[] m_name;
			m_name = nullptr;
			m_name = new char[strlen(na) + 1];
			strcpy(m_name, na);

		}
		if (number == 3) {
			delete[] l_name;
			l_name = nullptr;
			l_name = new char[strlen(na) + 1];
			strcpy(l_name, na);
		}
	}

	void Name::setShort(bool valid)
	{
		if ((valid == true)&&(m_name!=nullptr))
		{
			m_name[1] = '.';
			m_name[2] = '\0';
		}
	}
	Name& Name::operator=(const Name& copy)
	{
		if (( * this).f_name != copy.f_name)
		{
			set(copy.f_name, 1);
			set(copy.m_name, 2);
			set(copy.l_name, 3);
		}
		return *this;
	}
	Name::~Name()
	{
		delete[] f_name;
		f_name = nullptr;
		delete[] m_name;
		m_name = nullptr;
		delete[] l_name;
		l_name = nullptr;
	}

	std::ostream& Name::printIDInfo(std::ostream& ostr) const
	{
		ostr << f_name << " " << m_name << " " << l_name;

		return ostr;// // O: insert return statement here
	}

	std::ostream& Name::print(std::ostream& ostr, bool toFile) const
	{
		ostr << f_name;
		if ((m_name != nullptr))
		{
			ostr << " " << m_name;
		}
		if ((l_name != nullptr))
		{
			ostr << " " << l_name;
		}
		return ostr;
	}

	std::istream& Name::read(std::istream& istr)
	{
		char fn[50]{ '\n' };
		char mn[50]{ '\n' };
		char ln[50]{ '\n' };
		this->setEmpty();

		istr >> fn;
		if (istr.peek() == '\n')
		{
			istr.ignore();
			set(fn, 1);
		}
		else if (true)
		{
			istr >> mn;
			if (istr.peek() == '\n')
			{
				istr.ignore();
				set(fn, 1);
				set(mn, 3);//  LIKE THE LAST NAME 
			}
			else if (true) {
				istr >> ln;
				if (istr.peek() == '\n')
				{
					istr.ignore();
					set(fn, 1);
					set(mn, 2);
					set(ln, 3);//  LIKE THE LAST NAME //  LIKE THE LAST NAME 
				}
			}
		}
		return istr;
	}


	Name& Name::operator+=(const char* name_value)
	{
		int k = 0;
		int support = 0;
		
		while (*(name_value) != '\0')
		{
			if (name_value[k] == ' ')
			{
				support = 2;
				break;
			}
			if (name_value[k] == '\0')
			{
				break;
			}
			k++;
			
			
		}
	if ((name_value != nullptr) &&(support==0)&&((*(name_value) != '\0')))
		{
		
			if (f_name == nullptr)
			{
				set(name_value, 1);
			}
			else {
				if (m_name == nullptr)
				{
					set(name_value, 2);
				}
				else if (l_name == nullptr) {
					set(name_value, 3);
				}
				else {
					setEmpty();
				}
			}
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& ostr, const Name& name_value)
	{
		
		if (name_value.f_name!=nullptr)
		{
			name_value.print(ostr, true);
		}
		else
		{
			std::cout << "Bad Name";
		}
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Name& name_va)
	{
		return name_va.read(istr);
	}
}

