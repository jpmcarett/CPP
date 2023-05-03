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
#include "Line.h"
#include <string>

using  namespace std;
namespace sdds{
	
	void Line::getSpecs(istream& ist)
	{
		char support[1000];
		LblShape::getSpecs(ist);
		ist.getline(support, '\n');
		m_length = stoi(support);
	}
	void Line::draw(ostream& os) const
	{
		if((m_length>0) && (label() != nullptr))
		{
			os <<label()<<endl;
			int val = 0;
			while (val<m_length)
			{
				os << "=";
				val++ ;
			}

		}
	}
}
