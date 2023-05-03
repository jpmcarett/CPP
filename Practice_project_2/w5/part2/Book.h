/*Workshop 5 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 02 / 19 / 2023/
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
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
		const std::string& title() const { return _title; }
		const std::string& country() const { return _country; }
		const size_t& year() const { return _year; }
		double& price() { return _price; }
		friend std::ostream& operator<<(std::ostream& ost, const Book& prBook);
		//second part
		template<typename T>
		void fixSpelling(T& spellChecker) { spellChecker(_des); }
	};
	std::string trim(std::string& clean);
}

#endif // !SDDS_BOOK_H

