#include <iostream>
#include <iomanip>
#include <fstream>
#include "Utilities.h"
#include "Utilities.h"
#include "College.h"
#include "College.h"

void loadData(const char* filename, sdds::College& theCollege)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	sdds::Person* thePerson = nullptr;
	while (file)
	{
		try
		{
			thePerson = sdds::buildInstance(file);
			if (thePerson)
				theCollege += thePerson;
		}
		catch (std::string err)
		{
			std::cout << err << std::endl;
		
		}
	
		
	}
}


int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::College theCollege;
	loadData(argv[1], theCollege);
	theCollege.display(std::cout);

	return 0;
}
