/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:20/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Status.h"
#include "Utils.h"

namespace sdds {

	Status::operator bool() const
	{
		bool flag = true;

		if ((this->s_status != nullptr))
		{
			flag = false;
		}
		return flag;
	}

	Status::operator char* () const
	{
		return s_status;
	}

	Status::operator int() const
	{
		return s_Code;
	}

	Status::Status(char* descrip, int sCo)
	{
		if (descrip != nullptr)
		{
			ut.alocpy(s_status, descrip);
		}
		else
		{
			s_status = nullptr;
		}
		s_Code = 0;
	}

	int Status::operator=(int sco)
	{
		this->s_Code = sco;
		return this->s_Code;
	}

	char Status::operator=(const char* des)
	{
		ut.alocpy(s_status, des);
		return *this->s_status;
	}

	// copy constructor
	Status::Status(const Status& copy)
	{
		*this = copy;
	}
	Status& Status::operator=(const Status& st)
	{
		if (this!=&st)
		{
			if (st.s_status != nullptr) {
				ut.alocpy(s_status, st.s_status);
				s_Code = st.s_Code;
			}
		}
		return *this;
	}
	// clear function
	Status& Status::clear()
	{
		delete[] s_status;
		s_status = nullptr;
		s_Code = 0;
		return *this;
	}
	//DESTRUCTOR
	sdds::Status::~Status()
	{
		delete[] s_status;
		s_status = nullptr;
	}

	std::ostream& Status::print(std::ostream& ostr) const
	{
		if (s_Code != 0)
		{
			ostr << "ERR#" << s_Code << ": ";
		}
		ostr << s_status;
		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Status& check)
	{
		if (check.s_status != nullptr)
		{
			check.print(ostr);
		}
		return ostr;
	}
}