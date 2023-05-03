// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:01/16/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H
#include <istream>

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {

	class FoodOrder {

		char m_customerOrder[11]{};
		char m_foodDescription[26]{};
		double priceFood{};
		bool specialDay = true;
	public:
		FoodOrder()=default;// constructor
		std::istream& read(std::istream& in);
		void display() const;


};

}

#endif // SDDS_FOODORDER_H
