/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:30/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef HTMLTEXT_H
#define HTMLTEXT_H
#include "Text.h"

namespace sdds
{
	class HtmlText: public Text
	{
		char* m_title{};


	public:
		HtmlText(){ m_title = nullptr; };
		HtmlText(const char* title);
		HtmlText(const HtmlText&);
		ostream& write(ostream& ostr)const ;
		HtmlText& operator=(const HtmlText&);
		~HtmlText() ;
	};

}

#endif
