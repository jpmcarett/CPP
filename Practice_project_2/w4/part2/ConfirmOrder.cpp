/*Workshop 4 part 2
Name: Juan Pablo Martinez Carett
Module : ConfirmationSender
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 02 / 12 / 2023*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "ConfirmOrder.h"
using namespace std;
namespace sdds {

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
	{
		bool flag = true;
		for (size_t i = 0; i < count_trac; i++)
		{
			if (_toyConfir[i] == &toy)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			
				const Toy** confiOrder = new const Toy * [count_trac + 1];
				for (size_t i = 0; i < count_trac; i++)
				{
					confiOrder[i] = _toyConfir[i];
				}
				confiOrder[count_trac] = &toy;
				delete[] _toyConfir;
				_toyConfir = confiOrder;
			
			count_trac++;
		}

		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
	{
		bool flag = false;
		size_t pos{};
		size_t index{};
		if (count_trac != 0)
		{
			for (size_t i = 0; i < count_trac; i++)
			{
				if (_toyConfir[i] == &toy)
				{
					flag = true;
					pos = i;
					break;
				}
			}
			if (flag)
			{
				const Toy** confiOrder = new const Toy * [count_trac - 1];
				for (size_t i = 0; i < count_trac; i++)
				{
					if (i != pos)
					{
						confiOrder[index] = _toyConfir[i];
						index++;
					}

				}
				delete[] _toyConfir;
				_toyConfir = confiOrder;
				count_trac--;
			}
		}

		return *this;

	}

	ConfirmOrder::ConfirmOrder(const ConfirmOrder& src)
	{

		*this = src;
	}

	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& src)
	{
		if (this != &src)
		{
			if (_toyConfir)
			{
				delete[] _toyConfir;
				_toyConfir = nullptr;
			}
			_toyConfir = src._toyConfir;

			count_trac = src.count_trac;
			_toyConfir = new const Toy * [count_trac];

			for (size_t i = 0; i < count_trac; i++)
			{
				_toyConfir[i] = src._toyConfir[i];
			}

		}
		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& src)
	{

		if (this != &src)
		{
			if (_toyConfir != nullptr)
			{

				delete[] _toyConfir;
				_toyConfir = nullptr;
				count_trac = 0;
			}
			count_trac = src.count_trac;
			_toyConfir = src._toyConfir;
			src._toyConfir = nullptr;
			src.count_trac = 0;
		}
		return *this;



	}
	ConfirmOrder::ConfirmOrder(ConfirmOrder&& src)noexcept
	{
		*this = std::move(src);
	}
	std::ostream& operator<<(std::ostream& out, const ConfirmOrder& input)
	{


		out << "--------------------------\n";
		out << "Confirmations to Send\n";
		out << "--------------------------\n";
		if (input.count_trac != 0)
		{
			for (size_t i = 0; i < input.count_trac; i++)
			{
				out << *input._toyConfir[i];
			}

		}
		else
		{
			out << "There are no confirmations to send!" << std::endl;
		}
		out << "--------------------------\n";
		return  out;
	}

};