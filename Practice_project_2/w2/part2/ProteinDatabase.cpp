// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:01/29/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <fstream>
#include <iostream>
#include <utility>
#include "ProteinDatabase.h"

using namespace std;
namespace sdds {
	ProteinDatabase::ProteinDatabase(std::string file_name)
	{
		std::string _temporal{};
		std::string _temporal2{};

		ifstream f(file_name);
		if (f)
		{
			while(!f.eof()){
			getline(f, _temporal, '>');
			_temporal = "";
			s_counter++;
			}
			tracker = new string[s_counter];
			f.clear();
			f.seekg(0, std::ios::beg);
			s_counter = 0;
			_temporal = " ";
			while (!f.eof()) {
				getline(f, _temporal, '\n');
				_temporal = " ";
				while( f.peek()!='>' && !f.eof()){
				getline(f, _temporal, '\n');
				_temporal2 += _temporal;
				}
				tracker[s_counter] = _temporal2;
				_temporal2 = "";
				s_counter++;
			}
		}
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& input)
	{
		*this = input;
	}

	//copy aasigment
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src)
	{
		if (this!=&src)
		{
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
		
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& input) //noexcept
	{
		*this = move(input);
	}
	
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase &&input) // noexcept
	{
		
		if (this == &input)
			return *this;

		s_counter = 0;
		delete[] tracker;
		s_counter = input.s_counter;
		input.s_counter = 0;
		tracker = input.tracker;
		input.tracker = nullptr;
		return *this;
	}
	ProteinDatabase::~ProteinDatabase()
	{
		if (tracker != nullptr){
			delete[] tracker;
		}

	}

	size_t ProteinDatabase::size() const
	{
		return s_counter;;
	}
	
	std::string ProteinDatabase::operator[](size_t index) const
	{
		string _helper{};
		
		if (index < s_counter)
		{
			return tracker[index];		
		}
		return _helper;
	}

}