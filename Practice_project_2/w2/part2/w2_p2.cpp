// Workshop 2 - Copy and Move Semantics
// w2_p2.cpp
// 2021/11/28 - Mufleh Al-Shatnawi

#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include "ProteinDatabase.h"
#include "ProteinDatabase.h" // intentional
#include "TimedTask.h"
#include "TimedTask.h" // intentional

using namespace sdds;

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	if (argc == 1)
	{
		std::cerr << "ERROR: Missing file name!\n";
		return 1;
	}
	else if (argc != 2)
	{
		std::cerr << "ERROR: Too many arguments!\n";
		return 2;
	}

	sdds::TimedTask t;
	{
		t.startClock();
		sdds::ProteinDatabase protein_DBA;
		t.stopClock();
		t.addTask("  0-arg Constructor");
		std::cout << "  0-arg Constructor - protein_DBA.size = "
			<< std::setw(7) << protein_DBA.size() << " strings -> \n";
		std::cout << std::setw(70) << "(a) String     1: [" << protein_DBA[  0] << "]\n";
		std::cout << std::setw(70) << "(a) String   100: [" << protein_DBA[ 99] << "]\n";
		std::cout << std::setw(70) << "(a) String  1000: [" << protein_DBA[999] << "]\n";
		std::cout << std::setw(70) << "(a) String  last: [" << protein_DBA[protein_DBA.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(a) String last+: [" << protein_DBA[protein_DBA.size()] << "]\n\n";


		t.startClock();
		ProteinDatabase protein_DBB(argv[1]);
		t.stopClock();
		t.addTask("  1-arg Constructor");
		auto cnt = protein_DBB.size();
		std::cout << "  1-arg Constructor - protein_DBB.size = "
		          << std::setw(7) << cnt << " strings -> \n";
		std::cout << std::setw(70) << "(b) String     1: ["
		          << protein_DBB[  0].size()                               << "]["
		          << protein_DBB[  0].substr(0, 20)                        << "]["
		          << protein_DBB[  0].substr(protein_DBB[  0].size() - 20) << "]\n";
		std::cout << std::setw(70) << "(b) String   100: ["
		          << protein_DBB[ 99].size()                               << "]["
		          << protein_DBB[ 99].substr(0, 20)                        << "]["
		          << protein_DBB[ 99].substr(protein_DBB[ 99].size() - 20) << "]\n";
		std::cout << std::setw(70) << "(b) String  1000: ["
		          << protein_DBB[999].size()                               << "]["
		          << protein_DBB[999].substr(0, 20)                        << "]["
		          << protein_DBB[999].substr(protein_DBB[999].size() - 20) << "]\n";
		std::cout << std::setw(70) << "(b) String  last: ["
		          << protein_DBB[cnt - 1].size()                           << "]["
		          << protein_DBB[cnt - 1].substr(0, 20)                    << "]["
		          << protein_DBB[cnt - 1].substr(protein_DBB[cnt - 1].size() - 20) << "]\n";
		std::cout << std::setw(70) << "(b) String last+: [" << protein_DBB[protein_DBB.size()] << "]\n\n";


		t.startClock();
		ProteinDatabase protein_DBC{ protein_DBB };
		t.stopClock();
		t.addTask("  Copy Constructor");
		std::cout << "  Copy Constructor  - protein_DBC.size = "
			<< std::setw(7) << protein_DBC.size() << " strings -> \n";
		std::cout << std::setw(70) << "(c) String     1: [" << protein_DBC[0].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(c) String   100: [" << protein_DBC[99].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(c) String  1000: [" << protein_DBC[999].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(c) String  last: [" << protein_DBC[protein_DBC.size() - 1].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(c) String last+: [" << protein_DBC[protein_DBC.size()] << "]\n\n";


		t.startClock();
		protein_DBA = protein_DBB;
		t.stopClock();
		t.addTask("  Copy Assignment");
		std::cout << "  Copy Assignment   - protein_DBA.size = "
			<< std::setw(7) << protein_DBA.size() << " strings -> \n";
		std::cout << std::setw(70) << "(a) String     1: [" << protein_DBA[0].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String   100: [" << protein_DBA[99].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String  1000: [" << protein_DBA[999].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String  last: [" << protein_DBA[protein_DBA.size() - 1].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String last+: [" << protein_DBA[protein_DBA.size()] << "]\n\n";
		
		
		protein_DBA = protein_DBA;

		t.startClock();
		ProteinDatabase protein_DBD = std::move(protein_DBA);
		t.stopClock();
		t.addTask("  Move Constructor");
		std::cout << "  Move Constructor  - protein_DBD.size = "
			<< std::setw(7) << protein_DBD.size() << " strings -> \n";
		std::cout << std::setw(70) << "(a) String     1: [" << protein_DBA[0] << "]\n";
		std::cout << std::setw(70) << "(a) String   100: [" << protein_DBA[99] << "]\n";
		std::cout << std::setw(70) << "(a) String  1000: [" << protein_DBA[999] << "]\n";
		std::cout << std::setw(70) << "(a) String  last: [" << protein_DBA[protein_DBA.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(a) String last+: [" << protein_DBA[protein_DBA.size() + 4] << "]\n\n";
		std::cout << std::setw(70) << "(d) String     1: [" << protein_DBD[0].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(d) String   100: [" << protein_DBD[99].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(d) String  1000: [" << protein_DBD[999].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(d) String  last: [" << protein_DBD[protein_DBD.size() - 1].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(d) String last+: [" << protein_DBD[protein_DBD.size() + 5] << "]\n\n";


		protein_DBD = std::move(protein_DBD);


		t.startClock();
		protein_DBA = std::move(protein_DBD);
		t.stopClock();
		t.addTask("  Move Assignment");
		std::cout << "  Move Assignment   - protein_DBA.size = "
			<< std::setw(7) << protein_DBA.size() << " strings -> \n";
		std::cout << std::setw(70) << "(a) String     1: [" << protein_DBA[0].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String   100: [" << protein_DBA[99].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String  1000: [" << protein_DBA[999].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String  last: [" << protein_DBA[protein_DBA.size() - 1].substr(0, 20) << "]\n";
		std::cout << std::setw(70) << "(a) String last+: [" << protein_DBA[protein_DBA.size() + 6] << "]\n\n";
		std::cout << std::setw(70) << "(d) String     1: [" << protein_DBD[0] << "]\n";
		std::cout << std::setw(70) << "(d) String   100: [" << protein_DBD[99] << "]\n";
		std::cout << std::setw(70) << "(d) String  1000: [" << protein_DBD[999] << "]\n";
		std::cout << std::setw(70) << "(d) String  last: [" << protein_DBD[protein_DBD.size() - 1] << "]\n";
		std::cout << std::setw(70) << "(d) String last+: [" << protein_DBD[protein_DBD.size() + 7] << "]\n";


		t.startClock();
	}
	t.stopClock();
	t.addTask("  Destructor");

	std::cout << t;
}