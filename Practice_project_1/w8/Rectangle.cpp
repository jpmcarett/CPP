/* ------------------------------------------------------
Workshop 8 part 1
Name: Juan Pablo Martinez Carett
Module: Rectangle
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:26/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Rectangle.h"
#include <string>
namespace sdds
{
	void Rectangle::getSpecs(istream& ist)
	{
		char support[1000];
		LblShape::getSpecs(ist);
		ist.getline(support, 10,',');
		 m_width= stoi(support);
		 support[0] = {'\n'};
		 ist.getline(support, '\n');
		 m_height = stoi(support);
	}
	void Rectangle::draw(ostream& ost) const
	{
		if ((m_height>0)&&(m_width>0))
		{
			//first line
			ost << "+";
			ost.fill('-');
			ost.width((m_width - 1));
			ost << "+"<<endl;
			//Second line
			ost << "|";
			ost << label();
			ost.fill(' ');
			ost.width(m_width - 1 - strlen(label()));

			ost << "|"<<endl;
			// fourth line
			if (m_height-3>1)
			{
				//third line
				ost << "|";
				ost.fill(' ');
				ost.width((m_width - 1));
				ost << "|" << endl;	
			}
			ost << "|";
			ost.fill(' ');
			ost.width((m_width - 1));
			ost << "|" << endl;
			// last line
			ost << "+";
			ost.fill('-');
			ost.width((m_width - 1));
			ost << "+";
		}
	}
}
