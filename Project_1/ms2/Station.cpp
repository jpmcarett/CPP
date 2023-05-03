// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:04/03/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iomanip>
#include "Station.h"


using namespace std;
namespace sdds {


	size_t Station::id_generator = 0;
	size_t Station::m_widthField = 0;

	Station::Station(const string token) {
		Utilities _temp{};
		_id = ++id_generator;
		size_t pos = 0;
		bool flag = true;
		_name = _temp.extractToken(token, pos, flag);
		_nextSerial = stoi(_temp.extractToken(token, pos, flag));
		_number = stoi(_temp.extractToken(token, pos, flag));
		m_widthField = max(_temp.getFieldWidth(), m_widthField);

		flag = false;
		_desc = _temp.extractToken(token, pos, flag);


	}

	void Station::display(std::ostream& os, bool full) const
	{


		string delimiter = " | ";
		os << right << setw(3) << setfill('0') << _id << delimiter;
		os << left << setw(15) << setfill(' ') << _name << delimiter;
		os << right << setw(6) << setfill('0') << _nextSerial;

		if (full)
		{
			os << " | " << right << setw(4) << setfill(' ') << _number << delimiter;
			os << _desc;
		}
		else
		{
			os << " | ";
		}
		os << endl;
	}


}