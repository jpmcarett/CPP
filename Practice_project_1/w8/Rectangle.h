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
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "LblShape.h"
#include <string.h>

using  namespace  std;
namespace sdds {

	class Rectangle : public  LblShape
	{
	private:
		int m_width;
		int m_height;

	public:
		Rectangle() :LblShape(nullptr) { m_height = 0; m_width = 0; };
		Rectangle(const char* label, int width, int height):LblShape(label)
		{
			int value = strlen(LblShape::label());
			if ((height>=3)&& (width>value))
			{
				m_height = height;
				m_width = width;
			}
			else
			{
				m_height = 0;
				m_width = 0;
			}
		};
		~Rectangle(){};
		void getSpecs(istream&);
		void draw(ostream&)const;
	};

}



#endif