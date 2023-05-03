/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:09/04/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_ITEM
#define SDDS_ITEM
#include <ostream>
#include "iProduct.h"
#include "Status.h"
namespace sdds {
	class Item :public iProduct
	{
		double m_price = 0.00;
		int m_qty = 0;
		int m_qtyNeeded = 0;
		char* m_description{}; 
		bool m_linear = false;
	protected:
		Status i_status;// Item status
		int m_sku = 0;
		bool linear() const;
	public:
		
		Item();
		~Item();
		Item(const Item&);
		Item& operator=(const Item & It);
		//VIRTUAL QUERY
		int qtyNeeded()const; // ok
		int qty()const;//ok
		operator double()const;// ok

		operator bool()const;
		//VIRTUAL MODIFIER
		int operator-=(int qty);// OK
		int operator+=(int qty);// OK
		void linear(bool isLinear);// OK
		// PUBLIC MODIFIER
		void clear() { i_status.clear(); };
		//VIRTUAL OPERATOR 
		bool operator==(int sku)const;// OK
		bool operator==(const char* description)const;// OK
		// VIRTUAL INPUT/OUTPUT METHOD
		virtual std::ofstream& save(std::ofstream& ofstr)const;
		virtual std::ifstream& load(std::ifstream& ifstr);//ok
		virtual int readSku(std::istream& istr);//ok
		virtual std::ostream& display(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);//
	};
}

#endif