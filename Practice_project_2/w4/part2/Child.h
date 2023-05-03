/*Workshop 4 part 2
Name: Juan Pablo Martinez Carett
Module : ConfirmationSender
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 02 / 12 / 2023*/
/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#pragma once
#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H
#include "Toy.h"

namespace sdds {
	class Child {

		std::string _name{};
		int _age{};
		 Toy* _toy{nullptr};// composition with Toy class
		size_t counter{};
	public:
		Child(std::string name, int age, const Toy* toys[], size_t count);
		size_t size() const;
		// assigment operator
		Child& operator=(const Child& source);
		// move assigment operator
		Child& operator=(Child&& source)noexcept;
		//copy constructor
		Child(const Child& copy);
		//move  copy constructor
		Child(Child&& copy)noexcept ;
		//Deconstructor
		~Child();


		friend std::ostream& operator<<(std::ostream& out, const Child& input);
	};
}


#endif // !SDDS_CHILD_H

