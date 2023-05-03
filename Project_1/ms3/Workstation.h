// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:04/09/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#pragma once

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <string>
#include <deque>
#include "CustomerOrder.h"

namespace sdds 
{
	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

class Workstation:public Station {

	std::deque<CustomerOrder> m_orders{};
	Workstation* m_pNextStation{nullptr}; 

public:

	Workstation(const std::string& inValue) :Station(inValue) {};
	Workstation(const Workstation&) = delete;
	Workstation(Workstation&&) = delete;
	Workstation& operator=(const Workstation&) = delete;
	Workstation& operator=(Workstation&&) = delete;


	void fill(std::ostream& os);

	bool attemptToMoveOrder();

	void setNextStation(Workstation* station = nullptr) { m_pNextStation = station; };

	Workstation* getNextStation() const { return m_pNextStation; };

	void display(std::ostream& os) const;

	Workstation& operator+=(CustomerOrder&& newOrder);

	//the function who check that status of the Workstation
	bool filled_check() const{ return m_orders.empty(); };

};


}
#endif