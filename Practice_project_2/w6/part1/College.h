#pragma once
#ifndef SDDS_COLLEGE_H
#define Sdds_COLLEGE_H
#include <vector>
#include "Person.h"


namespace sdds {

	class College {
		std::vector<Person*> m_persons{};
	public:
		College() {};
		College(const College& other) = delete;
		College& operator=(const College& other) = delete;
		College& operator +=(Person* thePerson);
		//Use Person::display() for the first test, and use the 
		//other public functions for the second test. To iterate 
		//over the elements of the vector, use STL iterators!
		void display(std::ostream& out) const;
		~College()
		{
			for (Person* _vehi : m_persons)
				delete _vehi;
		};


	};

	



}


#endif // !SDDS_COLLEGE_H


