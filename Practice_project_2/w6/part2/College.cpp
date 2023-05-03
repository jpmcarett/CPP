/*Workshop 6 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 03 / 12 / 2023/
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.*/
#include <iomanip>
#include "College.h"

using namespace std;
namespace sdds {

	College& College::operator+=(Person* thePerson)
	{
		m_persons.push_back(thePerson);
		return *this;
	}

	void College::display(std::ostream& out) const
	{
		static size_t num_per = 1;
		size_t len = m_persons.size();

		out << std::string(120,'-')<< endl;
		out << "|                                        Test #" << num_per++ << " Persons in the college!                                               |" << endl;
		out << std::string(120, '-') << endl;
		for (auto pos = m_persons.begin(); pos!=m_persons.end();pos++)
		{
			(*pos)->display(out);
			out << endl;

		}
		out << std::string(120, '-') << endl;
		out << "|                                        Test #" << num_per++ << " Persons in the college!                                               |" << endl;
		out << std::string(120, '-') << endl;

		for (size_t i=0;i<len;i++)
		{
			out << "|";
			out.fill(' ');
			out << setw(9) << left;
			out<< this->m_persons[i]->status();
			out.fill(' ');
			out << " | ";
			out << setw(9) << left;
			out << this->m_persons[i]->id() << " | ";
			out.fill(' ');
			out << setw(20);
			out << this->m_persons[i]->name() << " | ";

			out.fill(' ');
			out << setw(3);
			out << this->m_persons[i]->age() << " |" << endl;
		}
		out << std::string(120, '-') << endl;
	}
}


