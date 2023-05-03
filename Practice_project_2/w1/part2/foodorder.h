// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:01/22/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds
{
	class FoodOrder {
		char c_order[10]{};
		char* f_description{ nullptr };
		double priceFood{};
		bool specialDay = true;
	public:
		FoodOrder() {};// constructor
		std::istream& read(std::istream& in);
		void display() const;
		FoodOrder& operator=(const FoodOrder&);
		FoodOrder(const FoodOrder& copy);
		~FoodOrder() {
			if (f_description!=nullptr)
			{
				delete[] f_description;
				f_description = nullptr;
				priceFood = -1;
				c_order[0] = '\0';
			}
		}
	};
}
#endif // SDDS_FOODORDER_H
