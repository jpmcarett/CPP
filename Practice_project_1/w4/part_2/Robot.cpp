/* ------------------------------------------------------
Workshop 4 part 2
Name: Juan Pablo Martinez Carett
Module: Robot
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:2/13/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <iomanip>
#include "Robot.h"

using namespace std;
namespace sdds
{
	Robot::Robot()
	{
		name = nullptr;
		location = nullptr;
		weight = 0;
		width = 0;
		height = 0;
		speeds = 0;
		deployed = false;
	}// set the default contructor to dhe empty state;

	Robot::Robot(const char* n, const char* l, double we, double wi, double h, double s, bool d)
	{
		//set(n, l, we, wi, h, s, d);
		this->setName(n);
		this->setLocation(l);
		weight = we;
		width = wi;
		height = h;
		speeds = s;
		this->setDeployed(d);
	}

	Robot& Robot::set(const char* n, const char* le, double we, double wi, double h, double s, bool d)
	{
		// dealocate the past memory
		delete[] name;
		delete[] location;
		name = nullptr;
		location = nullptr;
		// rest of the the set function 
		name = new char[strlen(n)+1];
		strcpy(name, n);
		//Location
		location = new char[strlen(le)+1];
		strcpy(location, le);
		//weight
		this->weight = we;
		//width
		this->width = wi;
		//height
		this->height = h;
		//speed
		this->speeds = s;
		//deployed
		this->deployed = d;
		return *this;

	}

	void Robot::setName(const char* n)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	void Robot::setLocation(const char* l)
	{
		location = new char[strlen(l) + 1];
		strcpy(location, l);

	}
	void Robot::setDeployed(bool d)
	{
		this->deployed = d;
	}

	const char* Robot::getName() const
	{
		return name;
	}
	const char* Robot::getLocation() const
	{
		return location;
	}

	const bool Robot::isDeployed() const
	{
		return deployed;
	}
	const double Robot::getWeight() const
	{
		return weight;
	}

	const bool Robot::isValid() const
	{
		bool flag = false;
		if ((name != nullptr) && (location != nullptr) && (weight > 0) && (width > 0) && (height > 0) && (speeds > 0))
		{
			flag = true;
		}
		return flag;
	}
	const double Robot::speed() const
	{
		return speeds;
	}

	void Robot::display() const
	{
		int lent = 0;
		cout << "| ";
		cout << name;
		lent = strlen(name);
		cout.width(13 - lent);
		cout << "| ";
		cout << location;
		lent = strlen(location);
		cout.width(18 - lent);
		cout << "| ";
		cout.width(6);
		cout << fixed << setprecision(1);
		cout << weight;
		cout << " | ";
		cout.width(6);
		cout << width;
		cout << " | ";
		cout.width(6);
		cout << height;
		cout << " | ";
		cout.width(6);
		cout << speeds;
		cout << " | ";
		cout << (((this->deployed) == 1) ? "YES" : "NO");
		((this->deployed) == 1 ? cout.width(7) : cout.width(8));
		cout << "|" << endl;
	}
	int conrtolRooomReport(const Robot robot[], int num_robots)
	{
		int j = 0;
		int support = 0;
		int num_deployed = 0;
		int posi_faster = 0;
		display_he();
		for (j = 0; j < num_robots; j++)
		{
			if (robot[j].isValid())
			{
				robot[j].display();
				if (robot[j].isDeployed() == true)
				{
					num_deployed++;
				}
				if (robot[posi_faster].speed() < robot[j].speed())
				{
					posi_faster = j;
				}
				if (j == (num_robots - 1))
				{
					support = -1;			
				}
			}
			else
			{
				support = j;
				j = num_robots;
			}
		}
		if (support == -1)
		{
			cout<<"|=============================================================================|" << endl;
			cout<<"| SUMMARY:                                                                    |" << endl;
			cout<<"| " << num_deployed << "  robots are deployed.                                                     |" << endl;
			cout<<"| The fastest robot is:                                                       |" << endl;
			cout<<"| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
			cout<<"|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
			robot[posi_faster].display();
			cout<<"|=============================================================================|" << endl;
		}
		return support;
	}

	void display_he()
	{
		cout << setw(55) << "------ Robot Control Room -----" << endl;
		cout << setw(59) << "---------------------------------------" << endl;

		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
	}

	Robot::~Robot()
	{
		delete[] name;
		delete[] location;
		name = nullptr;
		location = nullptr;
	}
}