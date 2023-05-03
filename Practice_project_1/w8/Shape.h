/* ------------------------------------------------------
Workshop 8 part 1
Name: Juan Pablo Martinez Carett
Module: Shape
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:26/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SHAPE_H
#define SHAPE_H
#include <ostream>

namespace sdds
{
	class Shape
	{
	public:
		virtual ~Shape()= default ; // ok
		virtual void draw(std::ostream&) const=0; // ok
		virtual void getSpecs(std::istream&)=0; // ok

		friend std::ostream& operator<<(std::ostream& ost, const Shape& da);
		friend std::istream& operator>>(std::istream& ist, Shape& da);
	};
}


#endif
