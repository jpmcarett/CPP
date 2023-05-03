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
			out << setw(12) << right << in._task[i].task_duration.count(); // revisar esta propiedad luego
			out << in._task[i].unit_time << endl;
		}
		out << "--------------------------\n";
		
		// TODO: insert return statement here
		return out;
	}

}