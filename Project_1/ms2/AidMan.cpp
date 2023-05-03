#include <iostream>
#include "AidMan.h"
#include "Utils.h"
#include "Status.h"
#include  "Date.h"

using  namespace std;

namespace sdds
{
	unsigned  AidMan::menu() const
	{
		unsigned option = 18;

		cout << "Aid Management System Version 0.1" << endl;
		cout << "Date: " << Date() << endl;
		if (filename==nullptr)
		{
			cout << "Data file: No file" << endl;
		}
		else
		{
			cout << "Data file:" << filename << endl;
		}
		cout << "---------------------------------" << endl;

		
		option =m_menu.run();
		return option;
	}



	void AidMan::run()
	{
		int out = 30;
		while (out != 0)
		{
			out = menu();
			switch (out) {
			case 1:
				cout << endl << "****" << "List Items" << "****" << endl << endl;
				break;
			case 2:
				cout << endl << "****" << "Add Item" << "****" << endl << endl;
				break;
			case 3:
				cout << endl << "****" << "Remove Item" << "****" << endl << endl;
				break;
			case 4:
				cout << endl << "****" << "Update Quantity" << "****" << endl << endl;
				break;
			case 5:
				cout << endl << "****" << "Sort" << "****" << endl << endl;
				break;
			case 6:
				cout << endl << "****" << "Ship Items" << "****" << endl << endl;
				break;
			case 7:
				cout << endl << "****" << "New/Open Aid Database" << "****" << endl << endl;
				break;
			}



		}

		cout <<"Exiting Program!"<<endl;

	}
	
}





