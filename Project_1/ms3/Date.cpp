/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:20/3/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Date.h"
#include <iostream>
#include <ostream>
#include <istream>



namespace sdds {
	bool Date::validate()
	{
		int m_da=0;
		bool flag = false;
		if ((year >= sdds_testYear) && (year <= MAX_YEAR_VALUE))
		{
			if ((month > 0) && (month < 13))
			{
				m_da = ut.daysOfMon(month, year);
				if ((day > 0) && (day <= m_da))
				{
					flag = true;
				}
				else
				{
					m_state.operator=("Invalid day in date");
					m_state.operator=(3);
				}
			}
			else
			{
				m_state.operator=("Invalid month in date");
				m_state.operator=(2);
			}
		}
		else
		{
			m_state.operator=("Invalid year in date");
			m_state.operator=(1);
		}
		return flag;
	}

	int Date::unique(int year, int mon, int day)
	{
		int value = 0;
		value = year * 372 + mon * 31 + day;
		return value;
	}

	Date::Date(int m_year, int m_month, int m_day)
	{
		if ((m_year==0)&&(m_month==0))
		{
			ut.getSystemDate(&this->year,&this->month,&this->day);
		}
		else
		{
			this->day = m_day;
			this->month = m_month;
			this->year = m_year;
		}
		this->validate();
	}

	const Status& sdds::Date::state()
	{
		return m_state;
	}

	Date& Date::formatted(bool s_state)
	{
		this->m_formatted = s_state;
		return *this;
	}

	Date::operator bool() const
	{
		return *this->m_state;
	}

	bool Date::operator==(const Date& rvalue)
	{
		bool checker = false;
		if (unique(this->year, this->month, this->day) == unique(rvalue.year, rvalue.month, rvalue.day))
		{
			checker = true;
		}
		return checker;
	}

	bool Date::operator!=(const Date& rvalue)
	{
		bool checker = false;
		if (unique(this->year, this->month, this->day) != unique(rvalue.year, rvalue.month, rvalue.day))
		{
			checker = true;
		}
		return checker;
	}

	bool Date::operator<(const Date& rvalue)
	{
		bool checker = false;
		if (unique(this->year, this->month, this->day) < unique(rvalue.year, rvalue.month, rvalue.day))
		{
			checker = true;
		}
		return checker ;
	}

	bool Date::operator>(const Date& rvalue)
	{
		bool checker = false;
		if (unique(this->year, this->month, this->day) > unique(rvalue.year, rvalue.month, rvalue.day))
		{
			checker = true;
		}
		return checker;
	}

	bool Date::operator<=(const Date& rvalue)
	{
		bool checker = false;
		if (unique(this->year, this->month, this->day) <= unique(rvalue.year, rvalue.month, rvalue.day))
		{
			checker = true;
		}
		return checker;
	}

	bool Date::operator>=(const Date& rvalue)
	{
		bool checker = false;
		if (unique(this->year, this->month, this->day) >= unique(rvalue.year, rvalue.month, rvalue.day))
		{
			checker = true;
		}
		return checker;
	}

	std::istream& Date::read(std::istream& istr)
	{
		int value;
		bool flag = false;
			istr >> value;
			if (!value)
			{
				std::cout << "Invalid date value";
				istr.setstate(std::ios::badbit);
			}
			else
			{
				if (value<100)
				{
					month = 0;
					day = value;
				}
				else if (value<10000)
				{
					day = value/100;
					month = value % 100;
				}
				else if (value<1000000)
				{
					day = value % 100;
					month = ((value % 10000)-day)/100;
					year = (value / 10000)+2000;
				}
				flag=validate();
				if (!flag)
				{
					istr.setstate(std::ios::badbit);

				}
			}

		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const
	{
		if (this->m_formatted==true)
		{

			ostr << year << "/";
			ostr.width(2);
			ostr.fill('0');
			ostr<< month;
			ostr << "/";
			ostr<< day;		}
		else
		{
			ostr << year-2000;
			ostr.width(2);
			ostr.fill('0');
			ostr << month;;
			ostr << day;

		}
		return ostr;
	}

	Date::Date(const Date& copy)
	{
		if (this!=&copy)
		{
			this->year = copy.year;
			this->month = copy.month;
			this->day = copy.day;
			this->m_formatted = copy.m_formatted;
			this->m_state = copy.m_state;}		
	}

	Date::~Date()
	{
		
	}

	std::ostream& operator<<(std::ostream& ostr,const Date& da)
	{
		da.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Date& da)
	{
		return da.read(istr);
	}
}