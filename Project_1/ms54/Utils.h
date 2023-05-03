/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:09/04/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
	const int sdds_testYear = 2022;
	const int sdds_testMon = 03;
	const int sdds_testDay = 31;
	class Utils {
		bool m_testMode = false;
	public:
		void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
		int daysOfMon(int mon, int year)const;
		void testMode(bool testmode = true);
		/*Recommende methods*/
		void alocpy(char*& destination, const char* source);// OK TO CHECK
		int getint(const char* prompt = nullptr);// OK TO CHECK
		int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);// OK TO CHECK
		double getdouble(const char* prompt = nullptr);// OK TO CHECK
		double getdouble(double min, double max, const char* prompt = nullptr, const char* errMes = nullptr);
	};
	extern Utils ut;
}

#endif // !SDDS_UTILS_H
