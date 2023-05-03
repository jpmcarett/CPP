#pragma once
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>
namespace sdds {

	class Book {
		std::string _autor{};
		std::string _title{};
		std::string _country{};
		size_t _year{};
		double _price{};
		std::string _des{};

	public:
		Book() {};
		Book(const std::string& strBook);
		std::string trim(std::string& clean);
		const std::string& title() const { return _title; }
		const std::string& country() const { return _country; }
		const size_t& year() const { return _year; }
		double& price() { return _price; }
		
		friend std::ostream& operator<<(std::ostream& ost, const Book& prBook);
		
	};


}

#endif // !SDDS_BOOK_H

