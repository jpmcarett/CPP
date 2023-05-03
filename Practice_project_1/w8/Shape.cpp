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
#include "Shape.h"
using namespace  std;
namespace sdds
{
	ostream& operator<<(ostream& ost, const Shape& da)
	{
		da.draw(ost);
		return ost;
	}

	istream& operator>>(istream& ist, Shape& da)
	{
		da.getSpecs(ist);
		return ist;
	}
}