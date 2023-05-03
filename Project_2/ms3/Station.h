// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:04/03/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include "Utilities.h"
namespace sdds {
	class Station {

		size_t _id{};
		std::string _name{};
		std::string _desc{};
		size_t  _nextSerial{};
		size_t _number{};

		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string& token);
		const std::string& getItemName() const { return _name; };
		size_t getNextSerialNumber() { return _nextSerial++; };
		size_t getQuantity() const { return _number; };
		void updateQuantity() { _number > 0 ? _number-- : _number; };
	
		void display(std::ostream& os, bool full) const;
	};
}


#endif // !SDDS_STATION_H

