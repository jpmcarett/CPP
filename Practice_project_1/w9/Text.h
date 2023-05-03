/* ------------------------------------------------------
Workshop 8 part 1
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:30/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include <ostream>
#ifndef TEXT_H
#define TEXT_H
using namespace std;
namespace sdds
{
	class Text
	{
		char* m_conten{} ;
	protected:
		const char& operator[](int index)const;
	public:
		//constructor
		Text() { m_conten = nullptr; };
		//
		~Text();
		Text(const Text&);
		istream& read(istream& istr);
		virtual ostream& write(ostream& ostr)const;
		int getFileLength(istream& is);

		//operator const char()const;
		Text& operator=(const Text&);
		friend ostream& operator << (ostream& ost, const Text& te) ;
		friend istream& operator >> (istream& ist, Text& te);

	};
	

}

#endif
