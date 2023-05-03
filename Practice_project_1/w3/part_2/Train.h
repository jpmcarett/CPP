/* ------------------------------------------------------
Workshop 3 part 2
Name: Juan Pablo Martinez Carett
Module: Train
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:2/5/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef TRAIN_H // replace with relevant names
#define TRAIN_H

namespace sdds{
const int MAX_NAME_LEN = 20;
const int MAX_PEOPLE = 1000;
const int  MAX_SPEED = 320;

class Train
{
// private part
	char train_name[MAX_NAME_LEN +1]="0"; // name of the train
	int numb_passenger=0; // number of passenger per train
	double speedT=0; // train's speed
public:
	// the mutator function
	void set(const char*, int, double);
	// The Query function
	void display () const;

	//Safe empty state is number_passenger=0 and speedT=0
	// that mean the train is not working at this moment.
	bool isSafeEmpty();
	//If you want to get only the number of people 
	int getNumberOfPeople();
	//If you want to get only the name of the train 
	const char* getName() const;
	//If you want to get only the speed train
	double getSpeed() const;
	bool changeSpeed(double);
	bool loadPeople(int);
	
}; 
//This function adds the difference between the maximum passenger valuesand the actual values in "first" and reduce that value from "second"
int transfer(Train& first, Train& second);
}



#endif