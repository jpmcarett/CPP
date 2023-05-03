// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:01/29/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
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

		ProteinDatabase(ProteinDatabase&& input); //noexcept;
	

		ProteinDatabase& operator=(ProteinDatabase&& input);// noexcept;// move assigment

		~ProteinDatabase();                   //deconstructor
		
		size_t size() const;                        //Query that retunr the number of sequences
		
		std::string operator[](size_t index) const; //query that return the sequnce
		


	};


}


#endif // !SDDS_PROTEINDATABASE_H

