/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:20/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef MENU_H
#define MENU_H


namespace  sdds
{
	class Menu
	{
		char* m_content{};
		unsigned number_option;
	public:

		Menu( unsigned number , const char* text );
		unsigned run() const; // Check at the end if you need to change that like unsigned
		~Menu();
	};

}
#endif // !MENU_H