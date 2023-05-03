// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:04/03/2023 - Update 04/09/2023 
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iomanip>
#include "Station.h"

using namespace std;

namespace sdds {

	size_t Station::id_generator = 0;
	size_t Station::m_widthField = 0;

	Station::Station(const std::string& token)
	{
		Utilities _tempUtil{};
		_id= ++id_generator;
		size_t pos = 0;
		bool flag = true;
		_name = _tempUtil.extractToken(token, pos, flag);
		_nextSerial = stoi(_tempUtil.extractToken(token, pos, flag));
		_number = stoi(_tempUtil.extractToken(token, pos, flag));
		m_widthField = max(_tempUtil.getFieldWidth(), m_widthField);
		_desc = _tempUtil.extractToken(token, pos, flag);
	}


	void Station::display(std::ostream& os, bool full) const
	{
		string delimiter = " | ";
		os << right << setw(3) << setfill('0') << _id << delimiter;
		os << left << setw(15) << setfill(' ') << _name << delimiter;
		os << right << setw(6) << setfill('0') << _nextSerial;
		if (full)
		{
			os << delimiter << right << setw(4) << setfill(' ') << _number << delimiter;
			os << _desc;
		}
		else
			os << delimiter;
		
		os << endl;
	}
}
