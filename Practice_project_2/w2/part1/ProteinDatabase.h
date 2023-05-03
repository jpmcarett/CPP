#pragma once
#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H
#include <string>

namespace sdds {

	class ProteinDatabase {

		std::string  *tracker{ nullptr };
		size_t s_counter{};


	public:
		ProteinDatabase() {};            //default constructor
		
		ProteinDatabase(std::string file_name);        //one argument constructor
		
		ProteinDatabase(const ProteinDatabase& input);//copy constructor

		ProteinDatabase& operator=(const ProteinDatabase& src);// copy assigment

		//ProteinDatabase(ProteinDatabase&& input); // move constructor

		//ProteinDatabase& operator=(ProteinDatabase&& input);//move assigment

		~ProteinDatabase();                   //deconstructor
		
		size_t size() const;                        //Query that retunr the number of sequences
		
		std::string operator[](size_t index) const; //query that return the sequnce
		


	};


}


#endif // !SDDS_PROTEINDATABASE_H

