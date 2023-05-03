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
#ifndef ROBOT_H 
#define ROBOT_H
namespace sdds
{
	class Robot
	{
		char* name;
		char* location;
		double weight;
		double width;
		double height;
		double speeds;
		bool deployed;

	public:
		Robot(); // set the default contructor to dhe empty state;
		
		Robot(const char* , const char* , double , double , double , double , bool );
		//Modifiers
		Robot& set(const char* , const char* , double ,double , double , double , bool );
		void setName(const char*);
		void setLocation(const char*);
		void setDeployed(bool);
		// Queries
		const char* getName() const;
		const char* getLocation() const;
		const double speed() const;
		const double getWeight() const;

		//double getWeight() const;
		const bool isDeployed() const;
		// Other public function
		const bool isValid() const;
		
		void display() const;
		~Robot();
	};

	int conrtolRooomReport(const Robot robot[], int num_robots);
	void display_he();
}
#endif