#include <string>
#include <iomanip>

#include "Pair.h"

namespace sdds{
	std::ostream& operator<<(std::ostream& ost,const Pair& info)
	{
		Pair _helper = info;
		ost << std::setw(20) << std::right;
		ost << _helper.getKey();
		ost << ": ";
		ost << _helper.getValue();
		return ost;
	}
	bool Pair::operator==(const Pair copy)
	{
		return m_key == copy.m_key ? true:false ;
	}
}