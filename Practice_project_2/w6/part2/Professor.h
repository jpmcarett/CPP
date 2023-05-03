/*Workshop 6 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 03 / 12 / 2023/
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.*/
#pragma once
#ifndef SDDS_PROFESSOR_H
#define SDDS_PROFESSOR_H
#include "Employee.h"

namespace sdds {
	class Professor : public Employee {
		std::string m_deparment{};
	public:
		Professor(std::istream& in);
		void display(std::ostream& out) const;
		std::string status() const;
		std::string department() const;
	};

}

#endif // !SDDS_PROFESSOR_H
