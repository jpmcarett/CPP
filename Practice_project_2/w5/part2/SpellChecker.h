/*Workshop 5 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 02 / 19 / 2023*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#pragma once
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string>
namespace sdds {
	class SpellChecker {

		std::string _badWords[6]{};
		std::string _goodWords[6]{};
		size_t countBadWord[6]{};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SDDS_SPEE\LLCHECKER_H