/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:09/04/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef MENU_H
#define MENU_H
#include "iProduct.h"
using  namespace std;
namespace  sdds
{
	class Menu
	{
		char* m_content{};
		unsigned number_option;

		//ms51 three private methos
		ofstream& save(ofstream& ofstr)const;
		ifstream& load(ifstream& ifstr);//ok
		void deallocate(iProduct& delet);// REIVSAR ESTO AL FINAL


	public:

		Menu( unsigned number , const char* text );
		unsigned run() const; // Check at the end if you need to change that like unsigned
		/* rule of three in menu*/
		~Menu();
	};

}
#endif // !MENU_H