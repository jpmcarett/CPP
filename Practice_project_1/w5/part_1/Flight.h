/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.h
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
Module: Flight
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:17/02/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------


*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;
   const int MinimunFuelRequirement = 600; // 600 per passenger

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;
      
      // operator bool
      operator bool() const;
      // operator int
      operator  int() const  ;
      //operator double
      operator  double()const;
      // operator string
      operator const char*()const;
      // oeprator string validate if you need that
      //Unary member 
      bool operator~() const;
      
      //binary member operator
      //assigment operator
       Flight& operator=(Flight& right); // complete fly;
       int& operator=( int );
       double& operator=(double );
       // += operator

       Flight& operator += (const double);
       Flight& operator += (const int);

       //-= operator
       Flight& operator -= (const double);
       Flight& operator -= (const int);
       //<< operator
       Flight& operator <<(Flight&);
      //>> operator
       Flight& operator >>(Flight&);

      // friend function         
      friend int operator+(const Flight&  , const Flight& );
      friend int operator +=(int&, const Flight&);

      


   };

}
#endif // SDDS_FLIGHT_H