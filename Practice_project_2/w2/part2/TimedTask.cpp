// Name: JUAN PABLO MARTINEZ CARETT
// Seneca Student ID: 112494216
// Seneca email:jpmartinez-carett@myseneca.ca
// Date of completion:01/29/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include "TimedTask.h"

using namespace std;
namespace sdds {

	void TimedTask::startClock()
	{
		 start_time = chrono::steady_clock::now();
	}

	void TimedTask::stopClock() {

		end_time = chrono::steady_clock::now();
	}
	
	void TimedTask::addTask(const char* input) {
		_task[num_record].task_name=input;
		_task[num_record].unit_time = " nanoseconds";
		_task[num_record].task_duration = end_time -start_time ;
		num_record++;
	}

	std::ostream& operator<<(std::ostream& out, const TimedTask& in)
	{
		out << "--------------------------\n";
		out << "Execution Times:\n";
		out << "--------------------------\n";
		for (size_t i = 0; i < in.num_record; i++)
		{
			out << setw(21) << left << in._task[i].task_name;
			out << setw(12) << right << in._task[i].task_duration.count(); 
			out << in._task[i].unit_time << endl;
		}
		out << "--------------------------\n";
		return out;
	}

}