/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:20/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef AIDMAN_H
#define AIDMAN_H
#include "Menu.h"
namespace  sdds
{
	class AidMan 
	{
		char* filename=nullptr;
		Menu m_menu;
		unsigned menu() const;
	public:
		AidMan() :m_menu(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n"){};
		
		void run();
	};

}


#endif // !AIDMAN_H