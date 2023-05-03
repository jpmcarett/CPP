// w4_p2.cpp - Containers
// 2021/12/02 - Miguel
// 2022/02/02 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Child.h"
#include "Child.h"
#include "ConfirmOrder.h"
#include "ConfirmOrder.h"
#include "Toy.h"
#include "Toy.h"

int cout = 0; // prevents compilation if headers don't follow convention

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n";

	const sdds::Toy** ppToys = nullptr;
	size_t count = 0;

	// Process the file
	if (argc > 1) {
		std::ifstream file(argv[1]);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}

		std::string strToy;
		// count how many records are in the file
		do
		{
			std::getline(file, strToy);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strToy[0] != '#')
					++count;
			}
		} while (file);

		ppToys = new const sdds::Toy*[count];
		count = 0;

		// read again from the file, but this time load and store data
		file.clear();
		file.seekg(std::ios::beg);
		do
		{
			std::getline(file, strToy);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strToy[0] != '#')
				{
					ppToys[count] = new sdds::Toy(strToy);
					++count;
				}
			}
		} while (file);
		file.close();
	}
	std::cout << "\nToys\n--------------------------\n";
	for (auto i = 0u; i < count; ++i)
	{
		std::cout << *ppToys[i];
	}
	std::cout << "--------------------------\n\n";

	{
		std::cout << "C: Testing Constructor\n";
		std::cout << "==========================\n";
		sdds::Child child1("Kyle Patel", 8, ppToys, count);
		std::cout << child1;  // 1
		std::cout << "==========================\n\n";

		std::cout << "C: Testing Copy Constructor\n";
		std::cout << "==========================\n";
		sdds::Child child2(child1);
		std::cout << child1;  // 2
		std::cout << child2;  // 3
		std::cout << "==========================\n\n";

		{
			std::cout << "C: Testing Copy Assign\n";
			std::cout << "==========================\n";
			child2 = child2;
			std::cout << child1;  // 4
			std::cout << child2;  // 5
			sdds::Child child3("Paul Sakuraba", 11, ppToys + 3, 4);
			child2 = child3;
			std::cout << child2;  // 6
			std::cout << child3;  // 7
			std::cout << "==========================\n\n";
		}

		std::cout << "C: Testing Move Constructor\n";
		std::cout << "==========================\n";
		sdds::Child child3(std::move(child2));
		std::cout << child2;  // 8
		std::cout << child3;  // 9
		std::cout << "==========================\n\n";

		std::cout << "C: Testing Move Assign\n";
		std::cout << "==========================\n";
		child3 = std::move(child3);
		std::cout << child2;  // 10
		std::cout << child3;  // 11
		child2 = std::move(child3);
		std::cout << child2;  // 12
		std::cout << child3;  // 13
		std::cout << "==========================\n\n";
	}


	// Confirm Order
	{
		std::cout << "CS: Testing Constructor\n";
		std::cout << "==========================\n";
		sdds::ConfirmOrder order1;
		std::cout << order1;
		std::cout << "==========================\n\n";

		std::cout << "CS: Testing Operators\n";
		std::cout << "==========================\n";
		order1 += *ppToys[5];
		order1 += *ppToys[6];
		order1 += *ppToys[6];
		order1 += *ppToys[8];
		order1 += *ppToys[7];
		order1 += *ppToys[9];
		std::cout << order1;
		order1 -= *ppToys[8];
		order1 -= *ppToys[9];
		order1 -= *ppToys[7];
		std::cout << order1;
		std::cout << "==========================\n\n";

		std::cout << "CS: Testing Copy Constructor\n";
		std::cout << "==========================\n";
		sdds::ConfirmOrder order2(order1);
		std::cout << order1;
		std::cout << order2;
		std::cout << "==========================\n\n";

		order2 = order2;

		std::cout << "CS: Testing Move Constructor\n";
		std::cout << "==========================\n";
		sdds::ConfirmOrder order3(std::move(order1));
		std::cout << order1;
		std::cout << order3;
		std::cout << "==========================\n\n";

		order3 = std::move(order3);
	}

	{
		// Making a new array of pointers to toy.
		//   The toys in this array are not constant, so we must
		//   create copies of the original toy (which are constant)
		sdds::Toy* toys[]{
								new sdds::Toy(*ppToys[3]),
								new sdds::Toy(*ppToys[5]),
								new sdds::Toy(*ppToys[7]),
								new sdds::Toy(*ppToys[9])
							};

		std::cout << "C + CS: Testing Relations\n";
		std::cout << "==========================\n";
		sdds::Child child("Tom Chow", 7, const_cast<const sdds::Toy**>(toys), 4u);
		sdds::ConfirmOrder order;
		(order += *toys[0]) += *toys[1];
		(order += *toys[2]) += *toys[3];
		std::cout << child;
		std::cout << order;

		// updating some toys in main
		//   child should not be affected
		//   confirm order should be affected
		toys[0]->update(6);
		toys[2]->update(4);

		std::cout << "\nAfter main() updates some toys ...\n\n";

		std::cout << child;
		std::cout << order;
		std::cout << "==========================\n\n";

		// cleanup
		for (auto item : toys)
			delete item;

	}

	// cleanup
	for (auto i = 0u; i < count; ++i)
		delete ppToys[i];
	delete[] ppToys;

	return 0;
}