#pragma once
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include "Pair.h"

namespace sdds {

	template<typename T, unsigned capacity>
	
	class Collection {
		T _collection[capacity]{};
		unsigned num_eleme{};
		static T dummy;
	public:

		unsigned size()const { return num_eleme; }
	    
		void display(std::ostream& out = std::cout) {//

			out << "----------------------" << std::endl;
			out << "| Collection Content |" << std::endl;
			out << "----------------------" << std::endl;
			for (size_t i = 0; i < num_eleme; i++)
			{
				out << _collection[i];
				out << "\n";
			}	
			out << "----------------------" << std::endl;

		}
		virtual bool add(const T& item) { // add va ser virtual en la segunda parte
			if (num_eleme < capacity)
			{
				_collection[num_eleme] = item;
				num_eleme++;
				return true;
			}
			else{return false;
			}
		};
		T operator[](size_t i)const{
			if (i >= num_eleme)
			{
				return dummy;
		    }
			else {
			return _collection[i];
			}
		}
		~Collection() {};
		
};
	

	template<typename T, unsigned capacity>
	T Collection<T, capacity>::dummy;
	template<>
	Pair Collection<Pair, 100>::dummy{"No key","No Value"};

	




}


#endif // !SDDS_COLLECTION_H

