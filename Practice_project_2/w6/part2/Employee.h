/*Workshop 6 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 03 / 12 / 2023/
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.*/
#pragma once
#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#include <string>
#include "Person.h"
namespace sdds {
	class Employee:public Person {
		
		std::string m_name{};
		size_t m_age{};
		std::string m_id{};
		
	public:
		Employee(std::istream& info);
		std::string status() const;
		std::string name() const;
		std::string id() const;
		std::string age() const;
		void display(std::ostream& out) const;
		

		// addicional function to clean the string 
	};
	std::string cleaner(std::string& to_clean);

}



#endif // !SDDS_EMPLOYEE_H

