/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.cpp
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
--
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds
{

	void Flight::emptyPlane() {
		m_passengers = 0;
		m_fuel = 0;
		strcpy(m_title, "EmptyPlane");
	}

	// New Flight
	Flight::Flight() {
		emptyPlane();
	}
	Flight::Flight(int passengers, double fuel, const char* title) {
		emptyPlane();
		if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
			fuel <= FuelTankCapacity) {
			m_passengers = passengers;
			m_fuel = fuel;
			strcpy(m_title, title);
		}
	}
	std::ostream& Flight::display() const {

		if (*this) {
			cout << " Flight  |  Ready to Depart";
			cout << " ";
			cout.width(10);
			cout << std::string(*this);
			cout << " | ";
			cout << "Pass: ";
			cout.width(10);
			cout << int(*this);
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << double(*this);
			cout.unsetf(ios::right);
			cout << " Liters";
		}
		else if (~*this) {
			cout << " Flight  |  Empty Plane    ";
		}
		else {
			cout << " Flight  |  Low Fuel       ";
			cout << " ";
			cout.width(10);
			cout << (const char*)(*this);
			cout << " | ";
			cout << "Pass: ";
			cout.width(10);
			cout << int(*this);
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << double(*this);
			cout.unsetf(ios::right);
			cout << " Liters";
		}
		return cout;
	}

	Flight::operator int() const
	{
		return m_passengers;
	}

	Flight::operator double() const
	{
		return m_fuel;
	}

	Flight::operator const char* () const
	{
		return this->m_title;
	}



	bool Flight::operator~() const
	{
		bool flag = false;
		if (this->m_passengers == 0)
		{
			flag = true;
		}
		return flag;
	}

	/*Flight::operator  std::string() const
	{
		return m_title;
	}*/

	Flight::operator bool() const
	{
		bool flag = false;
		if ((this->m_passengers > 0) && ((this->m_fuel / this->m_passengers) >= MinimunFuelRequirement))
		{
			flag = true;
		}
		return flag;


	}

	Flight& Flight::operator=(Flight& right)
	{

		this->m_passengers = right.m_passengers;
		this->m_fuel = right.m_fuel;
		strcpy(this->m_title, right.m_title);
		right.emptyPlane();
		return *this;
		// TODO: insert return statement here
	}

	int& Flight::operator=(int passenger)
	{
		if ((passenger > 0) && (passenger <= Boen747Capacity))
		{
			this->m_passengers = passenger;
		}
		else
		{
			this->m_passengers = 0;
		}
		return this->m_passengers;
	}

	double& Flight::operator=(double fuel)
	{

		if ((fuel > 0) && (fuel < FuelTankCapacity))
		{
			this->m_fuel = fuel;
		}
		else
		{
			this->m_fuel = 0;
		}

		return this->m_fuel;
	}

	Flight& Flight::operator +=(const double fuel)
	{
		if ((this->m_fuel == FuelTankCapacity) || fuel < 0)
		{
			// do nothing
		}
		else
		{
			if ((this->m_fuel+fuel>FuelTankCapacity))
			{
				this->m_fuel = FuelTankCapacity;
			}
			else
			{
				this->m_fuel += fuel;

			}
		}
		return *this;
	}

	Flight& Flight::operator+=(const int passenger)
	{
		int dif = 0;
		if ((this->m_passengers == Boen747Capacity) || (passenger < 0))
		{
			//do nothing
		}
		else
		{
			dif = Boen747Capacity - (this->m_passengers);
			if (dif < passenger)
			{

				this->m_passengers = Boen747Capacity;
			}
			else
			{
				this->m_passengers += passenger;
			}
		}
		// TODO: insert return statement here
		return *this;
	}

	Flight& Flight::operator-=(const double fuel)
	{
		double dif = 0;
		if (fuel < 0)
		{
			// do nothing
		}
		else
		{
			dif = (this->m_fuel - fuel);

			if (dif > 0)
			{
				this->m_fuel -= fuel;
			}
			else
			{
				this->m_fuel = 0;
			}
		}
		return *this;

		// TODO: insert return statement here
	}

	Flight& Flight::operator-=(const int passenger)
	{
		int dif = 0;
		if (passenger < 0)
		{
			//do nothing
		}
		else
		{
			dif = ((this->m_passengers) - passenger);
			if (dif > 0)
			{
				this->m_passengers -= passenger;
			}
			else
			{
				this->m_passengers = 0;
			}

		}
		// TODO: insert return statement here
		return *this;

		// TODO: insert return statement here
	}

	Flight& Flight::operator<<(Flight& right_aircraft)
	{
		int lef_pas = 0;
		int rig_pas = 0;
		int dif = 0;
		if ((this->m_passengers != Boen747Capacity) && (this->m_passengers != 0))
		{
			lef_pas = Boen747Capacity - this->m_passengers; // number of passenger allow in  left fly
		}
		if ((right_aircraft.m_passengers != Boen747Capacity) && (this->m_passengers != 0))
		{
			rig_pas = Boen747Capacity - right_aircraft.m_passengers; // number of passenger allow in  right fly
		}
		if ((rig_pas != 0) && (lef_pas != 0))
		{
			dif = lef_pas - rig_pas;
			if (dif > 0)
			{
				this->m_passengers += dif;

			}
			else
			{
				this->m_passengers = Boen747Capacity; // no sure about this part
			}
		}
		return *this;
		// TODO: insert return statement here
	}

	Flight& Flight::operator>>(Flight& right_aircraft)
	{
		int lef_pas = 0;
		int rig_pas = 0;
		if ((this->m_passengers != Boen747Capacity) && (this->m_passengers != 0))
		{
			rig_pas = Boen747Capacity - right_aircraft.m_passengers; // number of passenger allow in  left fly
		}
		if ((right_aircraft.m_passengers != Boen747Capacity) && (right_aircraft.m_passengers != 0)) {
			lef_pas = this->m_passengers - rig_pas;
		}
		if (rig_pas != 0)
		{

			right_aircraft.m_passengers += rig_pas;
			(*this).m_passengers = lef_pas;


		}
		return right_aircraft;
		// TODO: insert return statement here
	}

	int operator+(const Flight& one, const Flight& two)
	{
		int value = 0;
		value = one.m_passengers + two.m_passengers;
		return value;
	}

	int operator+=(int& value, const Flight& F)
	{
		value += F.m_passengers;


		return value;
	}

}