/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------
Workshop 5 part 1
Name: Juan Pablo Martinez Carett
Module: Porfolio
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:19/02/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;
      void emptyPortfolio();

   public:
       Portfolio();
       Portfolio(double value, const char* stock, char type);
       void dispPortfolio() const;
       std::ostream& display() const;
       //-------------------------------------------------//
       //operator double
       operator double()const;
       // operator string
       operator const char* ()const;
       // operator char 
       operator const char() const;
       // operator bool
       operator bool() const;

       Portfolio& operator += (const double);
       Portfolio& operator -= (const double);

       bool operator~() const;

       Portfolio& operator<<(Portfolio&);

       Portfolio& operator>>(Portfolio&);
       // friend function         
       friend double operator+(const Portfolio&, const Portfolio&);
       friend double operator+=(double&, const Portfolio&);

   };
}
#endif // SDDS_Portfolio_H_