/*Workshop 6 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 03 / 12 / 2023/
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.*/
#pragma once
#ifndef SDDS_COLLEGE_H
#define Sdds_COLLEGE_H
#include <vector>
#include <list>
#include "Person.h"


namespace sdds {

	class College {
		std::vector<Person*> m_persons{};
	public:
		College() {};
		College(const College& other) = delete;
		College& operator=(const College& other) = delete;
		College& operator +=(Person* thePerson);
		
		void display(std::ostream& out) const;
		~College()
		{
			for (Person* _index : m_persons)
				delete _index;
		};

		template<typename T>
		void select(T check, std::list<const Person*>& _person)
		{
			for (auto _temp : m_persons) {
				if (check(_temp))
					_person.push_back(_temp);
			}
		}

	};

	



}


#endif // !SDDS_COLLEGE_H


