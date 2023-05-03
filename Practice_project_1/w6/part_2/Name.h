/* ------------------------------------------------------
Workshop 6 part 2
Name: Juan Pablo Martinez Carett
Module: Name
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:10/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include <ostream>
#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H
namespace sdds{
	class Name {

		char* f_name{nullptr}; // firts name
		char* m_name{nullptr};// middle name
		char* l_name{nullptr};// last name
		void setEmpty(); 

	public:
		//constructor 
		Name(const char* f_name = nullptr, const char* m_name = nullptr, const char* l_name = nullptr);
		//copy constructor
		Name(const Name& nm);

		operator bool() const;
		
		void set(const char* na,int);
		void setShort( bool);
		Name& operator=(const Name&);
		~Name();
		std::ostream& printIDInfo(std::ostream& ostr)const;// ok
		std::ostream& print(std::ostream& ostr, bool toFile = true) const;
		std::istream& read(std::istream& istr);


		Name& operator +=(const char*); // 

		friend std::ostream& operator<<(std::ostream& ostr, const Name& hc);
		friend std::istream& operator>>(std::istream& istr, Name& hc);

	};
	
};



#endif // !SDDS_name_H