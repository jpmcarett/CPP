/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:09/04/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef AIDMAN_H
#define AIDMAN_H
#include "Menu.h"
namespace  sdds
{
	const int sdds_max_num_items = 100;
	class AidMan
	{
		iProduct *iproductArray[sdds_max_num_items]={};
		int track = 0;
		char* filename=nullptr;
		Menu m_menu;
		unsigned menu() const;
		//ms 51 option 7
		void save();
		void deallocate();
		bool load();
		int list(const char* sub_desc = nullptr);
		//ms52 option1
		int search(int sku) const;
	public:
		AidMan() :m_menu(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n") {};
		void run();
		~AidMan();


	};
}
#endif // !AIDMAN_H