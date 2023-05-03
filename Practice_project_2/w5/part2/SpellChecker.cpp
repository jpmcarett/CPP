/*Workshop 5 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 02 / 19 / 2023/
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#include<fstream>
#include <iomanip>
#include "SpellChecker.h"

using namespace std;
namespace sdds {





	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream f(filename);

		if (!f)
		{
			throw "Bad file name!";
		}
		else {

			std::string line{};
			std::string word{};
			size_t index = 0;
			size_t cont = 0;
			do
			{
				std::getline(f, line);
				if (f)
				{
					index = line.find(" ");
					_badWords[cont] = line.substr(0, index);
					line.erase(0, index + 1);
					while (!(line.find(" ")))
					{
						line.erase(0, 1);
					}
					_goodWords[cont] = line.substr(0, '\n');
					cont++;
				}

			} while (f);

		}
	}

	void SpellChecker::operator()(std::string& text)
	{
		for (auto i = 0; i < 6; ++i) {
			while (text.find(_badWords[i]) != std::string::npos) {
				text.replace(text.find(_badWords[i]), _badWords[i].size(), _goodWords[i]);
				++countBadWord[i];
			}
		}


	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < 6; i++)
		{
			//CHECK THIS CODE AT THE END
			out.fill(' ');
			out << std::setw(15) << std::right;

			out << _badWords[i] << ": ";
			out << countBadWord[i] << " replacements" << std::left << std::endl;
		}

	}


}