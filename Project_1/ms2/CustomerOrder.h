// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:04/04/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include "Station.h"
namespace sdds
{

	class CustomerOrder
	{

		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};

		std::string _name{};
		std::string _product{};
		size_t _cntItem{};
		Item** _lstItem{};
		static size_t _widthField;
	public:

		CustomerOrder() {};

		CustomerOrder(const std::string&);

		CustomerOrder(const CustomerOrder&) { throw "something is wrong"; };

		CustomerOrder& operator=(const CustomerOrder&) = delete;

		CustomerOrder(CustomerOrder&&) noexcept;


		CustomerOrder& operator=(CustomerOrder&&) noexcept;

		~CustomerOrder();

		bool isOrderFilled() const;

		bool isItemFilled(const std::string& itemName) const;

		void fillItem(Station& station, std::ostream& os);

		void display(std::ostream& os) const;
	};


}


#endif // !SDDS_CUSTOMERORDER_H

