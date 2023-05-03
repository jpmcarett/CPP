/*Workshop 6 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 03 / 12 / 2023/
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.*/
#include <sstream>
#include "Utilities.h"
#include "Employee.h"
#include "Student.h"
#include "Professor.h"


using namespace std;
namespace sdds {


	Person* buildInstance(std::istream& in)
	{
		string _helper{};
		string object{};

		getline(in, _helper);
		_helper.erase(0, _helper.find_first_not_of(' '));
		object = _helper.substr(0, _helper.find(','));
		_helper.erase(0, _helper.find(',') + 1);
		_helper.erase(0, _helper.find_first_not_of(' '));
		stringstream new_in(_helper);
		try
		{
			if (object[0] == 'e' || object[0] == 'E')
			{
				return new Employee(new_in);
			}
			else if(object[0] == 's' || object[0] == 'S')
			{
				return new Student(new_in);
			}
			else if (object[0] == 'p' || object[0] == 'P')
			{
				return new Professor(new_in);
			}
			else
			{
				return nullptr;
			}
		}
		catch (string msg)
		{
			throw  msg;
		}
	}

}



