// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:04/03/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
using namespace std;

namespace sdds
{
	char Utilities::m_delimiter = ',';
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_withField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_withField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		string _helper{};
		int pos = str.find(m_delimiter, next_pos);
		if (more)
		{
			_helper = str.substr(next_pos, pos - next_pos);
		}
		else
		{
			_helper = str.substr(next_pos, str.length());
		}
		if (more != false)
		{
			if (pos == static_cast<int>(next_pos))
			{
				more = false;
				throw " Error: no token. \n";
			}
			if (pos < 0)
				more = false;

		}
		//cleaner
		while (_helper[0] == ' ') {
			_helper.erase(0, 1);
		}
		while (_helper[_helper.length() - 1] == ' ') {
			_helper.erase(_helper.length() - 1, 1);
		}
		next_pos = static_cast<size_t>(pos) + 1;
		m_withField = max(_helper.length(), m_withField);
		return _helper;

	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}

};


