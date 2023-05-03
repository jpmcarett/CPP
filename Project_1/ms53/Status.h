/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:09/04/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef STATUS_H
#define STATUS_H
#include <ostream>
namespace sdds {
	class Status
	{
	private:

		char* description;// instruccion
		int sCode;// instruccion
	public:
		operator bool() const;
		operator char*() const;
		operator int() const;
		// constructor
		Status(char* m_description = nullptr, int m_sCode = 0);
		//--- 

		int operator=(int);
		char operator=( const char* );
	
		//--- COPY CONTRUCTOR
		Status(const Status& );
	     Status& clear();	 
		~Status();
		std::ostream& print(std::ostream& ostr) const;

		friend std::ostream& operator<<(std::ostream& ostr, const Status& );
	};
}

#endif // !STATUS_H