// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:04/03/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
namespace sdds {
	class Utilities {

		size_t m_withField = 1;
		static char m_delimiter;
	public:

		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}
#endif // !SDDS_UTILITIES_H

