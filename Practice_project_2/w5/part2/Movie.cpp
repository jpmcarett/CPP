/*Workshop 5 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 02 / 19 / 2023/
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#include <iostream>
#include <iomanip>
#include "Movie.h"
#include "Book.h"




using namespace std;

namespace sdds{
	Movie::Movie(const std::string& strMovie)
	{


		std::string tempMovie{};
		std::string temp{};
		size_t index = 0;
		tempMovie = strMovie;
		//title
		index = tempMovie.find(',');
		temp = tempMovie.substr(0, index);
		_title = sdds::trim(temp);
		tempMovie.erase(0, index + 1);
		// year
		index = tempMovie.find(',');
		_year = stoi(tempMovie.substr(0, index));
		tempMovie.erase(0, index + 1);
		//m_description
		temp = " ";
		index = tempMovie.find('\n');
		temp = tempMovie.substr(0, index);
		_des = trim(temp);
	}

	std::ostream& operator<<(std::ostream& os, const Movie& prinMovie)
	{
		//TITLE
		os.fill(' ');
		os << std::setw(40) << std::right;;
		os << prinMovie._title;
		os << " | ";
		//YEAR
		os.fill(' ');
		os << std::setw(4) << std::right;;
		os << prinMovie._year;
		os << " | ";
		//DESCRIPTION
		os << prinMovie._des << std::endl;
		return os;
	}

};
