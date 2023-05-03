#include <sstream>
#include "Utilities.h"
#include "Employee.h"

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
		
			if (object[0] == 'e' || object[0] == 'E')
			{
				try
				{
					return new Employee(new_in);
				}
				catch (string msg)
				{
					throw  msg;
				}
			}
			else
			{
				return nullptr;
			}
	}

}



