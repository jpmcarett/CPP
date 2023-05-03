// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:02/05/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#pragma once
#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <cmath>

namespace sdds {

	template<typename T,unsigned capacity=100 >
	class Set : public Collection<T,capacity > {
		T set_collection[capacity];
	public:

		bool add(const T& item) {
			bool check = false;
			for (size_t i = 0; i < 100; i++)
			{
				
				if (this->operator[](i) == item)
				{
					check =true;
					i = 100;
				}
			}
			if (!check)
			{
				this->push_in_collection(item);
			}
			return check;
		}
	};

	template<>// specialization double
	bool Set<double>::add(const double& item) {
		double med = 0.01;
		bool check = false;

		for (auto i = 0; i < (100 + 1); i++)
		{
			if (fabs(Collection<double, 100>::operator[](i) - item) <= med) {
				check = true;
				i = 100;
			}
		}
		if (!check)
		{
			this->push_in_collection(item);
		}
		return check;
	}

}
#endif // !SDDS_SET_H
