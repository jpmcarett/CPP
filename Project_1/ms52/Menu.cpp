/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:09/04/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include  <iostream>
#include "Menu.h"
#include "Utils.h"
using namespace  std;
namespace sdds
{
	 unsigned Menu::run() const
	{
		 unsigned option=0;
		 if (m_content!=nullptr)
		 {
			 cout << m_content << "0- Exit" << endl;
			 option = ut.getint(0, number_option, "> "); //  CHECK THIS PART AT THE END
		 }
		 return  option;
	}
	 Menu::Menu (unsigned int num,const char* option_list)
	 {
		 if ((num<15)||(option_list!=nullptr))
		 {
			 ut.alocpy(m_content,option_list);
			 number_option = num;
		 }
		 else
		 {
			 m_content = nullptr;
			 //number_option = 0;
		 }
	 }
	 Menu::~Menu()
	 {
		 delete[] m_content;
		 m_content = nullptr;
	 }
}