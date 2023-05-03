#pragma once
#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H
#define MAX_NUMBER 10
#include <chrono>
#include <string>


namespace sdds {
	

	

	class TimedTask {

		struct Task
		{
			
			std::string task_name;
			std::string unit_time;
			std::chrono::steady_clock::duration task_duration;
		};
		
		
		size_t num_record{};
		
		std::chrono::steady_clock::time_point start_time;
		std::chrono::steady_clock::time_point end_time;
		Task _task[MAX_NUMBER]{};




	public:
		//default constructor
		TimedTask() {};
		//
		//modifier that start the timer for an event
		void startClock();
		// modifier that stops the timer for the event
		void stopClock();

		void addTask(const char* input);

		friend	std::ostream& operator<<(std::ostream& out, const TimedTask& in);
	};
};




#endif // !SDDS_TIMEDTASK_H
