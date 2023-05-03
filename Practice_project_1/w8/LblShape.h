/* ------------------------------------------------------
Workshop 8 part 1
Name: Juan Pablo Martinez Carett
Module: LblShape
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:26/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {

	class LblShape: public Shape 
	{
	
		char *m_label{};
		
	protected :

		 char* label() const;
	
	public:
		LblShape();
		LblShape(const char *s_label); 
		~LblShape(){delete[] m_label;m_label = nullptr;};
		void getSpecs(istream&);
	};

}


#endif
