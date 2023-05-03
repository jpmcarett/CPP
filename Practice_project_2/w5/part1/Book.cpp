#include <iostream>
#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds{ 

	Book::Book(const std::string& input)
	{
		string copy = input;
		string _temp{};
		size_t index = 0;

		index = copy.find(',');
		_temp = copy.substr(0, index);
		//AUTHOR
		_autor = trim(_temp);
		copy.erase(0, index + 1);
		//TITLE
		_temp = " ";
		index = copy.find(',');
		_temp = copy.substr(0, index);
		_title = trim(_temp);
		copy.erase(0, index + 1);

		//COUNTRY
		_temp = " ";
		index = copy.find(',');
		_temp = copy.substr(0, index);
		_country = trim(_temp);
		copy.erase(0, index + 1);

		//PRICE
		_temp = " ";
		index = copy.find(',');
		_temp = copy.substr(0, index);
		_price = stod(trim(_temp));
		copy.erase(0, index + 1);
		//YEAR
		_temp = " ";
		index = copy.find(',');
		_temp = copy.substr(0, index);
		_year = stod(trim(_temp));
		copy.erase(0, index + 1);

		//DESCRIPTION
		//index = copy.find('.');
		//_temp = copy.substr(0, index);
		index = copy.find('.');
		_temp = copy.substr(0, index);
		_des = trim(_temp);

	}

	std::string Book::trim(std::string& clean)
	{
		// first position
		while (clean[0] == ' ') {
			clean.erase(0, 1);
		}
		//last position
		while (clean[clean.length() - 1] == ' ') {
			clean.erase(clean.length() - 1, 1);
		}
		return clean;
	}

	std::ostream& operator<<(std::ostream& ost, const Book& prBook)
	{
		//author
		ost.fill(' ');
		ost.width(20);
		ost << prBook._autor;
		//title
		ost << " | ";
		ost.fill(' ');
		ost.width(22);
		ost << prBook._title;
		//country
		ost << " | ";
		ost.fill(' ');
		ost.width(5);
		ost << prBook._country;
		//year
		ost << " | ";
		ost.fill(' ');
		ost.width(4);
		ost << prBook._year;
		//price
		ost << " | ";
		ost.fill(' ');
		ost.width(6);
		ost << setprecision(2) << std::fixed << prBook._price;
		//description
		ost << " | ";
		ost << prBook._des;
		ost << ".\n";
		// TODO: insert return statement here
		return ost;
		
	}

}