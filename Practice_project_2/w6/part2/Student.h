/*Workshop 6 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 03 / 12 / 2023/
I have done all the coding by myself and only copied the code that my 
professor provided to complete my workshops and assignments.*/
#pragma once
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include <string>
#include "Person.h"
namespace sdds {

	class Student :public Person {
		std::string m_name{};
		size_t m_age{};
		std::string m_id{};
		std::string* m_courses{};
		size_t m_count{};
	public:
		Student(std::istream& input);
		std::string status()const;
		std::string name() const;
		std::string age() const;// requirement for this application
		std::string id() const; // requirement for this application
		~Student();
		void display(std::ostream& out) const;
		Student(const Student& src) = delete;
		Student& operator=(const Student& src) = delete;

	};

}

#endif //SDDS_STUDENT_H