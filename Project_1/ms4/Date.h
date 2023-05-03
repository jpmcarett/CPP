/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:20/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef DATE_H
#define DATE_H
#include "Status.h"



namespace sdds {
	
	const int MAX_YEAR_VALUE = 2030;
	class Date
	{
	private:
		int year=0;
		int month=0 ;
		int day=0 ;
		Status d_state;
		bool m_formatted=true;
		// private methods
		bool validate();//ok
		int unique(int year, int mon, int day); // ok
	public:
	//Constructor
		Date(int m_year=0,int m_month=0,int m_day=0); // OK
     //state accessor

		const Status& state(); // return a state of the method
		// Formated modifier
		Date& formatted(bool); 
	 // Bool conversion
		operator bool() const; 
		//Copy constructor
		Date(const Date& cp);
		

		bool operator==( const Date&);
		bool operator!=( const Date&);
		bool operator<( const Date&);
		bool operator> ( const Date&);
		bool operator <=( const Date&);
		bool operator>=(const Date&);
		
		//read method
		std::istream& read(std::istream& istr);
		// write method
		std::ostream& write(std::ostream& ostr) const ; // check at the end this function
		
	//Destructor
		~Date();
			
		friend std::ostream& operator<<(std::ostream& ostr, const Date& da );
		friend std::istream& operator>>(std::istream& istr, Date& da );
	};

}

#endif // !DATE_H