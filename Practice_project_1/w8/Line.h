/* ------------------------------------------------------
Workshop 8 part 1
Name: Juan Pablo Martinez Carett
Module: Line
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:26/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef LINE_H
#define LINE_H
#include "LblShape.h"
namespace sdds {


	class Line :public LblShape
	{
		int m_length;

	public:
		Line() :LblShape(nullptr){m_length = 0; };
		Line(const char* s_label, int s_length):LblShape(s_label)
		{
			m_length = s_length;
		};
		~Line(){};
		void getSpecs(istream&);// check that at the end
		void draw(ostream&) const; // ok

	};
}
#endif