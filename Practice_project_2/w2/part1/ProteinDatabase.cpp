#include "ProteinDatabase.h"
#include <fstream>
#include <iostream>



using namespace std;
namespace sdds {




	ProteinDatabase::ProteinDatabase(std::string file_name)
	{
		std::string _temporal{};
		ifstream f(file_name);
		if (f)
		{
			while(!f.eof()){
			
			getline(f, _temporal, '\n');
			_temporal = " ";
			getline(f, _temporal, '>');

			s_counter++;
			}

			tracker = new string[s_counter];

			f.clear();
			f.seekg(0, std::ios::beg);

			s_counter = 0;
			while (!f.eof()) {
				getline(f, _temporal, '\n');
				_temporal = " ";
				getline(f, tracker[s_counter], '>');	
				s_counter++;
			}




		}
	





	}

	// OK POR REVISAR MAS TARDE
	//COPY CONSTRUCTOR
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& input)
	{
		*this = input;
	}

	//copy aasigment
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src)
	{
		if (this!=&src)
		{
            //validar 
			if (tracker != nullptr)
			{
				delete[] tracker;
				tracker = nullptr;
			}
			s_counter = src.s_counter;
			tracker = new string[s_counter];
			for (size_t i = 0; i < s_counter; i++)
			{
				tracker[i] = src.tracker[i];
			}
		}
		return *this;
		
		// TODO: insert return statement here
	}
	//MOVE CONSTRUCTOR
	//ProteinDatabase::ProteinDatabase(ProteinDatabase&& input)
	//{
	//	*this = std::move(input);
	//}
	//ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& input)
	//{
	//	if (this != &input)
	//	{
	//		//validar 
	//		if (tracker != nullptr)
	//		{
	//			delete[] tracker;
	//			tracker = nullptr;
	//		}
	//		s_counter = input.s_counter;
	//		input.s_counter = 0;

	//		tracker = input.tracker;
	//		input.tracker = nullptr;

	//		for (size_t i = 0; i < s_counter; i++)
	//		{
	//			tracker[i] = input.tracker[i];
	//		}
	//	}
	//	return *this;



	//}
	ProteinDatabase::~ProteinDatabase()
	{
		if (tracker != nullptr){
			delete[] tracker;
		}

	}
	// OK POR REVISAR
	size_t ProteinDatabase::size() const
	{
		return s_counter;;
	}
	// OK POR REVISAR
	std::string ProteinDatabase::operator[](size_t index) const
	{
		string _helper{};
		
		if (index < s_counter)
		{
			//helper=tracker[index];
			return tracker[index];
			
		}
		return _helper;

	}

}