/*Workshop 5 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 02 / 19 / 2023/
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#pragma once
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
namespace sdds {
	class Movie {
		std::string _title{};
		size_t _year{};
		std::string _des{};
	public:
		Movie() {};
		const std::string& title() const { return _title; }
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& os, const Movie& prinMovie);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(_title);
			spellChecker(_des);
		};
	};
}
#endif // !SDDS_MOVIE_H


