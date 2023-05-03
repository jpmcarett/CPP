/*Workshop 6 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 03 / 12 / 2023/
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.*/
#include "Professor.h"

using namespace std;
namespace sdds {

	Professor::Professor(std::istream& in):Employee(in)
	{
		string _aux{};
		getline(in, _aux);
		m_deparment = cleaner(_aux);

	}

	void Professor::display(std::ostream& out) const
	{
		Employee::display(out);
		
		out << m_deparment;
		out << "|";
		out << status(); 



	}

	std::string Professor::status() const
	{
		return " Professor";
	}

	std::string Professor::department() const
	{
		return m_deparment;
	}

};