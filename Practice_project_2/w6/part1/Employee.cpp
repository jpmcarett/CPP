#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"

using namespace std;
namespace sdds {

	Employee::Employee(std::istream& info)
	{
		string _temp{};



		getline(info, _temp);
		//m_status = _temp.substr(0, _temp.find(','));
		//cleaner(m_status);
		//_temp.erase(0, _temp.find(',') + 1);
		m_name = _temp.substr(0, _temp.find(','));
		cleaner(m_name);
		_temp.erase(0, _temp.find(',') + 1);
		m_age= stoi(_temp.substr(0, _temp.find(',')));
		_temp.erase(0, _temp.find(',') + 1);
		m_id = _temp.substr(0, _temp.find('\n'));
		cleaner(m_id);

		if (m_id[0]!= 'E')
		{
			string msg=(m_name+"++Invalid record!");

			throw (msg);
		}

		

	}

	std::string Employee::status() const
	{
		return std::string();
	}

	std::string Employee::name() const
	{
		
		return m_name;
	}

	std::string Employee::id() const
	{
		return m_id;
	}

	std::string Employee::age() const
	{
		return to_string(m_age);
	}

	void Employee::display(std::ostream& out) const
	{
		out << "| Employee  | ";
		
		out.fill(' ');
		out << setw(9) << left;
		out << m_id << " | ";

		out.fill(' ');
		out << setw(20) ;
		out << m_name << " | ";

		out.fill(' ');
		out << setw(3);
		out << m_age << " |"<<endl;

	}


std::string cleaner(std::string& to_clean)
{

	while (to_clean[0] == ' ') {
		to_clean.erase(0, 1);
	}

	while (to_clean[to_clean.size()-1] == ' ')
	{
		to_clean.erase(to_clean.size()-1);
	}

	return to_clean;
}


}



