/* ------------------------------------------------------
Workshop 3 part 2
Name: Juan Pablo Martinez Carett
Module: Train.cpp
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:02/05/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Train.h"


using namespace std;

namespace sdds
{

	void Train::set(const char* name, int number, double speed)
	{

		if ((MAX_PEOPLE >= number) && (number > 0) && (MAX_SPEED >= speed) && (speed > 0) && (name != nullptr) && (MAX_NAME_LEN >= strlen(name)) && (strlen(name) > 0))
		{
			strcpy(train_name, name);
			numb_passenger = number;
			speedT = speed;
		}
		else
		{
			strcpy(train_name, " ");
			numb_passenger = -1;
			speedT = -1.0;
		}
	}

	void Train::display() const
	{
		if ((numb_passenger == -1) && (speedT == -1.0))
		{
			cout << "Safe Empty State!" << endl;
		}
		else
		{
			cout << "NAME OF THE TRAIN : " << train_name << endl;
			cout << "NUMBER OF PEOPLE  : " << numb_passenger << endl;
			cout.setf(ios::fixed);
			cout.width(10);
			cout.precision(2);
			cout << "SPEED             : " << speedT << " km/h" << endl; // arreglar esto
		}
	}
	//Safe empty state is number_passenger=0 and speedT=0
	// that mean the train is not working at this moment.
	bool Train::isSafeEmpty()
	{
		if ((numb_passenger == -1) && (speedT == -1.0))
		{
			return true;
		}
		else
		{
			return false;
		}
		// return 
	}

	int Train::getNumberOfPeople()
	{

		return numb_passenger;

	}

	const char* Train::getName() const
	{
		return train_name;
	}

	double Train::getSpeed() const
	{
		return speedT;
	}

	bool Train::loadPeople(int change_people)
	{
		bool flag = false;
		if (((numb_passenger+change_people<0)||(numb_passenger + change_people > MAX_PEOPLE))|| ((numb_passenger == -1) && (speedT == -1.0)))
		{
			if (numb_passenger + change_people > MAX_PEOPLE)
			{
				numb_passenger = MAX_PEOPLE;
			}
			if (numb_passenger + change_people < 0)
			{
				numb_passenger = 0;
			}

			return flag;
		}
		else
		{
			numb_passenger += change_people;
			flag = true;
			return flag;
		}
	}

	bool Train::changeSpeed(double new_speed)
	{
		bool flag = false;
		
		if (((speedT+new_speed)<0)||((speedT + new_speed)>MAX_SPEED)||((numb_passenger == -1) && (speedT == -1.0)))
		{
			if (speedT+new_speed >MAX_SPEED)
			{
				speedT = MAX_SPEED;
			}
			if (speedT+new_speed<0)
			{
				speedT = 0;
			}
			return flag;
		}
		else
		{
			speedT += new_speed;
			flag = true;
			return flag;
		}
	}

	int transfer (Train& first, Train& second)
	{
		if ((first.isSafeEmpty())||(second.isSafeEmpty()))
		{
			return -1;
		}
		else
		{
			int dif_num_people = 0;
			dif_num_people = MAX_PEOPLE - first.getNumberOfPeople();
			first.loadPeople(dif_num_people);
			second.loadPeople(-dif_num_people);
			return dif_num_people;

		}
	}

}