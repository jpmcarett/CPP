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
#include <cstring>
#include <iostream>
#include "Status.h"
#include "Utils.h"

namespace sdds{

	Status::operator bool() const
{
	bool flag = true;
	if ((this->description!=nullptr))
	{
		flag = false;
	}
	return flag;
}

Status::operator char*() const
{
	return description;
}

Status::operator int() const
{
	return sCode;
}

Status::Status(char* descrip, int sCo)
{
	if (descrip!=nullptr)
	{
		ut.alocpy(description, descrip);}
	else
	{
		description = nullptr;
	}
	sCode = 0;
}

int Status::operator=(int sco)
{
	this->sCode = sco;
	return this->sCode;
}

char Status::operator=(const char* des)
{
	ut.alocpy(description, des);
	return *this->description;}

// copy constructor
Status::Status(const Status& copy)
{
	if(copy.description!=nullptr){
	description = nullptr;
	description = new char[strlen(copy.description) + 1];
	strcpy(description, copy.description);
	sCode = copy.sCode;
	}
}
// clear function
 Status& Status::clear()
{
		 delete[] description;
		 description = nullptr;
		 sCode = 0;
		 return *this;
}
 //DESTRUCTOR
sdds::Status::~Status()
{
	delete[] description;
	description = nullptr;
}

std::ostream& Status::print(std::ostream& ostr) const
{
	if (sCode != 0)
	{
		ostr << "ERR#" << sCode << ": ";
	}
	ostr << description;
	return ostr;
}

std::ostream& operator<<(std::ostream& ostr, const Status& check)
{
	if (check.description!=nullptr)
	{
		check.print(ostr);
	}
	return ostr;
}
}