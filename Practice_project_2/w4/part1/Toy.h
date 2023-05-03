#pragma once
#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <string>
namespace sdds {

	class Toy 
	{
		size_t order_id{};
		std::string name{};
		int num_item{};
		double price{};
		double har_tax = 0.13;
	public:
		Toy() {};
		Toy(const std::string& toy);
		void update(int numItems);
		friend std::ostream& operator<<(std::ostream& out, const Toy& input);
	};



}

#endif // !SDDS_TOY_H

