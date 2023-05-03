// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:04/09/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <fstream>
#include <algorithm>
#include "LineManager.h"


using namespace std;
namespace sdds {

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		Utilities Util_Obj;
		string aux1{}, aux2{}, aux3{};
		size_t pos{};
		bool flag = true;
		ifstream f(file);
		if (!f)
			throw string("Error opening the file");
		while (!f.eof())
		{
			flag = true;
			getline(f, aux1);
			aux2 = Util_Obj.extractToken(aux1, pos, flag);
			if (flag)
			{
				aux3 = Util_Obj.extractToken(aux1, pos, flag);
				auto b_station = find_if(begin(stations), end(stations), [&](Workstation* fisrt_station)
					{
						return fisrt_station->getItemName() == aux2;
					});
				auto f_station = find_if(begin(stations), end(stations), [&](Workstation* second_station)
					{
						return second_station->getItemName() == aux3;
					});

				(*b_station)->setNextStation(*f_station);
				m_activeLine.push_back(*b_station);
			}
			else
			{
				auto b_station = find_if(begin(stations), end(stations), [&](Workstation* fisrt_station)
					{
						return fisrt_station->getItemName() == aux2;
					});
				(*b_station)->setNextStation(nullptr);
				m_activeLine.push_back(*b_station);
				m_firstStation = *b_station;
			}
		}
		f.close();
	}

	void LineManager::reorderStations()
	{
		Workstation* aux_station = nullptr;
		vector<Workstation*> vector;
		bool flag = true;
		while (flag)
		{
			for (size_t i = 0; i < m_activeLine.size(); i++)
			{
				if (m_activeLine[i]->getNextStation() == aux_station)
				{
					vector.push_back(m_activeLine[i]);
					aux_station = m_activeLine[i];
				}
				if (vector.size() == m_activeLine.size())
				{
					flag = false;
					break;
				}
			}
		}
		reverse(begin(vector), end(vector));
		m_activeLine = vector;
		m_firstStation = vector[0];
	}

	bool LineManager::run(std::ostream& os)
	{
			bool check = true;
			

		static size_t count = 1;
		
		os << "Line Manager Iteration: " << count++ << endl;

		if (!g_pending.empty()) {
			(*m_firstStation) += move(g_pending.front());
			g_pending.pop_front();
		}

		for (unsigned int i = 0; i < m_activeLine.size(); i++) {
			m_activeLine[i]->fill(os);
		}

		for (unsigned int i = 0; i < m_activeLine.size(); i++) {
			m_activeLine[i]->attemptToMoveOrder();
			if (!m_activeLine[i]->filled_check())
				check = false;
		}
		return check;

	}

	void LineManager::display(std::ostream& os) const
	{
		for (size_t i = 0; i < m_activeLine.size(); i++) 
			m_activeLine[i]->display(os);
		
	}

}