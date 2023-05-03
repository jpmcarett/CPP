// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:04/09/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Workstation.h"


using namespace std;

namespace sdds {

	deque<sdds::CustomerOrder> g_pending;
	deque<sdds::CustomerOrder> g_completed;
	deque<sdds::CustomerOrder> g_incomplete;

	void Workstation::fill(ostream& os)
	{
		if (!m_orders.empty())
			m_orders.front().fillItem(*this, os);
	}
	bool Workstation::attemptToMoveOrder()
	{
		bool flag = false;
		if (filled_check())
			flag = true;
		else
		{
			if (m_orders.front().isItemFilled(getItemName()) || !(this->getQuantity())) {
				if (m_pNextStation != nullptr)
					(*m_pNextStation) += move(m_orders.front());
				else {
					if (m_orders.front().isOrderFilled())
						g_completed.push_back(move(m_orders.front()));
					else
						g_incomplete.push_back(move(m_orders.front()));
				}
				m_orders.pop_front();
				flag = true;
			}
		}
		return flag;
	}

	void Workstation::display(std::ostream& os) const
	{
		os << getItemName() << " --> ";
		if (m_pNextStation)
			os << m_pNextStation->getItemName() << endl;
		else
			os << "End of Line" << endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(move(newOrder));
		return *this;
	}
}
