// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:02/05/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#ifndef SDDS_PAIR_H
#define  SDDS_PAIR_H

namespace sdds {
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};
		Pair() {};
		// TODO: Add here the missing prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.
		bool operator==(const Pair copy);
		friend std::ostream& operator<<(std::ostream& ost, const Pair& info);
	};


}
#endif // !SDDS_PAIR_H

