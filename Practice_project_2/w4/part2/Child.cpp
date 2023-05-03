/*Workshop 4 part 2
Name: Juan Pablo Martinez Carett
Module : ConfirmationSender
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 02 / 12 / 2023*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "Child.h"


using namespace std;

namespace sdds {



	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	{
		_name = name;
		_age = age;
		counter = count;
		_toy = new Toy  [count];
		for (size_t i = 0; i < count; i++)
		{
			_toy[i] = *toys[i];
		}

	}

	size_t Child::size() const
	{
		return size_t();
	}

	Child& Child::operator=(const Child& source)
	{
		if (this != &source)
		{
			if (this->_toy != nullptr) {

				delete[] _toy;
				_toy = nullptr;
			}

			_name = source._name;
			_age = source._age;
			counter = source.counter;
			_toy = new Toy [counter];
			for (size_t i = 0; i < counter; i++)
			{
				_toy[i] = source._toy[i];
			}


		}

		return *this;
	}

	Child& Child::operator=(Child&& source) noexcept
	{
		if (this!=&source)
		{
			//delete[] _toy;
			
			_name = source._name;
			_age = source._age;
			counter = source.counter;
			source._name="";
			source._age=0;
			source.counter=0;
			_toy = source._toy;
			source._toy = nullptr;
			
		}
		return *this;
	}

	Child::Child(const Child& copy)
	{
		*this = copy;
	}

	Child::Child(Child&& copy) noexcept
	{
		if (copy._toy!=nullptr)
		{
			std::swap(_toy, copy._toy);
			_name = copy._name;
			_age = copy._age;
			counter = copy.counter;
			copy._name = "";
			copy._age = 0;
			copy.counter = 0;
			copy._toy = nullptr;

		}
		
		//*this = std::move(copy);

	}

	Child::~Child()
	{
		delete[] _toy;
		_toy = nullptr;
	}

	std::ostream& operator<<(std::ostream& out, const Child& input)
	{
		static int CALL_CNT=1;

		out << "--------------------------\n";
		out << "Child " << CALL_CNT << ": " << input._name << " " << input._age << " years old:\n";
		out << "--------------------------\n";
		if (input.counter==0)
		{
			out << "This child has no toys!\n";
		}
		else
		{
			for (size_t i = 0; i < input.counter; i++)
			{
				out<<input._toy[i];
			}
		}
		CALL_CNT++;


		out << "--------------------------\n";

		return out;
	}

};