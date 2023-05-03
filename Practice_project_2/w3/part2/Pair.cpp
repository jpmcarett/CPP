// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:02/05/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
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