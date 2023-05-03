/*Workshop 4 part 2
Name: Juan Pablo Martinez Carett
Module : ConfirmationSender
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 02 / 12 / 2023*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#pragma once
#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H
#include "Toy.h"

namespace sdds {
	class ConfirmOrder {
		const Toy** _toyConfir{nullptr}; // agregation with toy class
		size_t count_trac{};
	public:
		ConfirmOrder() {};
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		ConfirmOrder& operator=(const ConfirmOrder& src);
		ConfirmOrder(const ConfirmOrder& src);
		ConfirmOrder& operator=(ConfirmOrder&& src);
		ConfirmOrder(ConfirmOrder&& src) noexcept;
		~ConfirmOrder() {
				delete[] _toyConfir;
				_toyConfir = nullptr;
				count_trac = 0;
		}
		friend std::ostream& operator<<(std::ostream& out, const ConfirmOrder& input);

	};
}
#endif // !SDDS_CONFIRMORDER_H


