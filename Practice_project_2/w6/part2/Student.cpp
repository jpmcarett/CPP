/*Workshop 6 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 03 / 12 / 2023/
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.*/
#include <string>
#include <iomanip>
#include "Student.h"
#include "Employee.h"


using namespace std;
namespace sdds {

	Student::Student(std::istream& input)
	{
		string _temp{};
		string _aux{};
		getline(input, _temp,',');
		m_name = cleaner(_temp);
		getline(input, _temp, ',');
		try
		{
			m_age = stoi(_temp);

		}
		catch (...)
		{
			string msg = (m_name + "++Invalid record!");
			throw (msg);
		}
		getline(input, _temp, ',');
		m_id = cleaner(_temp);
		getline(input, _temp, ',');		
		m_count = stoi(_temp);
		getline(input, _temp, '\0');
		m_courses = new string[_temp.size()];
		for (size_t i = 0; i < m_count; i++)
		{
			_aux = _temp.substr(0, _temp.find(','));
			m_courses[i] = cleaner(_aux);
			_temp.erase(0, _temp.find(',') + 1);
		}



		if (m_id[0] != 'S')
		{
			string msg = (m_name + "++Invalid record!");

			throw (msg);
		}

	}

	string Student::status() const
	{
		return " Student  ";
	}

	string Student::name() const
	{
		return m_name;
	}

	std::string Student::age() const
	{
		return to_string(m_age);
	}

	std::string Student::id() const
	{
		return m_id;
	}

	Student::~Student()
	{
		delete[] m_courses;
	}



	void Student::display(std::ostream& out) const
	{
		out << "| Student   | ";
		out.fill(' ');
		out << setw(9) << left;
		out << m_id << " | ";

		out.fill(' ');
		out << setw(20);
		out << m_name << " | ";

		out.fill(' ');
		out << setw(3);
		out << m_age << " |";
		for (size_t i = 0; i < m_count; i++)
		{
			out << m_courses[i];
			if (i!=m_count-1)
			{

				out << ", ";
			}
		}
	
	}

}