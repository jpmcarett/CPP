/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:09/04/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "iProduct.h"
namespace sdds
{
	std::ostream& operator<<(std::ostream& ost, const iProduct& pro)
	{
		pro.display(ost);
		return  ost;
		// // O: insert return statement here
	}
	std::istream& operator>>(std::istream& ist, iProduct& pro)
	{
		pro.read(ist);
		return ist;
		// // O: insert return statement here
	}
	
}
