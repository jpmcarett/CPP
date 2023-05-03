/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:11/04/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "AidMan.h"
#include "Utils.h"
#include "Status.h"
#include  "Date.h"
#include "Perishable.h"

namespace sdds
{
	using  namespace std;
	unsigned  AidMan::menu() const
	{
		unsigned option = 18;
		cout << "Aid Management System" << endl;
		cout << "Date: " << Date() << endl;
		if (filename == nullptr)
		{
			cout << "Data file: No file" << endl;
		}
		else
		{
			cout << "Data file: " << filename << endl;
		}
		cout << "---------------------------------" << endl;
		option = m_menu.run();
		return option;
	}

	void AidMan::
		save()
	{
		int i = 0;
		if ((filename != nullptr) && (track != 0))
		{
			ofstream ofs(filename, ofstream::out);
			for (i = 0; i < track; i++)
			{
				iproductArray[i]->save(ofs) << "\n";
			}
		}
		else
		{
			// do nothing
		}
	}

	void AidMan::deallocate()
	{
		int i = 0;
		if (track != 0)
		{
			for (i = 0; i <= track; i++)
			{
				delete iproductArray[i];
				iproductArray[i] = nullptr;
			}
			delete[] filename;
			filename = nullptr;
			track = 0;
		}
	}

	bool AidMan::load()
	{
		bool flag = false;
		int option = 0;
		save();
		deallocate();
		if (filename != nullptr)
		{
			ifstream ifs;
			ifs.open(filename);
			if (!ifs)
			{
				cout << "Failed to open " << filename << " for reading!" << endl;
				cout << "Would you like to create a new data file?" << endl;
				cout << "1- Yes!\n0- Exit \n>";
				cin >> option; // you need yo used get int hre
				if (option == 1)
				{
					ofstream ofs(filename);
				}
			}
			else
			{

				while (!ifs.eof())// need to read until the last sentences
				{
					flag = true;
					//iProduct* Per=nullptr;
					bool flag2 = false;
					char value = ifs.peek();
					int val = (int)value - 48;

					if ((val > 0) && (val < 4))// persihable
					{
						iproductArray[track] = new Perishable;
						iproductArray[track]->load(ifs);
						flag2 = true;
					}
					if ((val > 3) && (val < 10))// Item
					{
						iproductArray[track] = new Item;
						iproductArray[track]->load(ifs);
						flag2 = true;
					}
					if (flag2 == false)
					{
						ifs.setstate(ios::badbit);
					}
					else
					{
						// check this part 
						if (iproductArray[track])// you are cheking this part in the bad way
						{
							
						}
						else
						{
							delete[] iproductArray[track];
							iproductArray[track] = nullptr;
						}
						track++;
					}
				}
			}

		}
		cout << track << " records loaded!" << endl << endl;
		return flag;
	}

	int AidMan::list(const char* sub_desc)
	{
		int k = 0;
		int j = 0;//variable created for the compiler
		char va;
		int opt = 0;
		int counter = 0;
		if ((sub_desc == nullptr) && (track != 0))
		{
			cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			for (k = 0; k < track; k++)
			{
				cout.width(4);
				cout.fill(' ');
				j = k + 1;
				cout << j;
				cout << " | ";
				iproductArray[k]->linear(true);
				iproductArray[k]->display(cout);
				cout << endl;

			}
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			cout << "Enter row number to display details or <ENTER> to continue:" << endl << "> ";
			cin.ignore();
			counter = k;
			cin.get(va);// change that
			opt = (int)va - 49;
		}
		else {
			if ((sub_desc != nullptr) && (track != 0))
			{
				cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
				cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
				for (k = 0; k < track; k++)
				{
					if (iproductArray[k]->operator==(sub_desc))
					{
						cout.width(4);
						cout.fill(' ');
						j = k + 1;
						cout << j;
						cout << " | ";
						iproductArray[k]->linear(true);
						iproductArray[k]->display(cout);
						cout << endl;
						counter++;
					}
				}
				cout << "-----+-------+-------------------------------------+------+------+---------+-----------";// << endl;

			}
		}
		if (sub_desc == nullptr)
		{
			if ((opt > 0) && (opt <= track))
			{
				iproductArray[opt]->linear(false);
				iproductArray[opt]->display(cout);

			}
			else if (counter == 0)
			{
				{
					cout << "The list is emtpy!";
				}
			}
		}
		cout << endl;

		return counter;
	}

	int AidMan::search(int sku) const
	{
		int k = 0;
		bool flag = false;
		int searching = -1;
		for (k = 0; k < +track; k++)
		{
			flag = (iproductArray[k]->operator==(sku));
			if (flag == true)
			{
				searching = k;
				k = track;

			}
		}
		if (flag == false)
		{
			if ((sku / 10000) < 4) //Perishable
			{
				//	iproductArray[track] = new Perishable;  CONST FUNCTION, i NEED TO CREATED THAT OUTSIDE
				iproductArray[track]->read(cin);
			}
			else//Item
			{
				iproductArray[track]->read(cin);
			}
			cout << endl;
		}
		else
		{
			//cout << "Sku: " << sku << " is already in the system, try updating quantity instead.\n\n";
		}
		return searching;
	}

	void AidMan::remove(int index)
	{
		int optRem = 0;
		int tra = 0;
		cout << "Following item will be removed: \n";
		iproductArray[index]->linear(false);
		iproductArray[index]->display(cout);
		cout << "\nAre you sure?" << endl;
		cout << "1- Yes!\n0- Exit\n> ";
		cin >> optRem;
		if (optRem==1)
		{
			
			cout << "Item removed!"<<endl<<endl;
			delete iproductArray[index];
			iproductArray[index] = nullptr;
			for (tra=index;tra<=track;tra++)
			{
				iproductArray[tra]= iproductArray[tra+1];
			}

		}
		delete iproductArray[track];
		iproductArray[track] = nullptr;
		track--;
		save();

	}

	void AidMan::run()
	{
		int out = 30;
		int opt2 = 0;
		bool flag = false;
		char name_file[50];
		char op3[3];
		while (out != 0)
		{
			out = menu();
			if ((filename == nullptr) && (flag == false))
			{
				out = 7;
			}
			switch (out) {

			case 1:// ms51
				//List Items
				cout << endl << "****" << "List Items" << "****" << endl;
				if (track != 0)
				{
					list(nullptr);
				}
				break;
				//Add Item
			case 2: // ms52
				cout << endl << "****" << "Add Item" << "****" << endl;
				if (track <= sdds_max_num_items)
				{

					cout << "1- Perishable\n" << "2- Non-Perishable\n" << "-----------------\n";
					cout << "0- Exit" << endl << "> ";
					scanf("%d", &opt2);
					if (opt2 == 0)
					{
						cout << "Aborted\n";
					}
					if (opt2 == 1)
					{
						iproductArray[track] = new Perishable;
						cout << "SKU: ";
						scanf("%d", &opt2);
						search(opt2);
					}
					if (opt2 == 2)
					{
						iproductArray[track] = new Item;
						cout << "SKU: ";
						scanf("%d", &opt2);
						search(opt2);
					}
					if (iproductArray[track]->qty() != 0)// because I found the value in the iproductArray, I need to delete the new that it created before 
					{
						track++;
						//save();
					}
					else
					{
						delete iproductArray[track];
						iproductArray[track] = nullptr;
					}
				}
				else
				{
					cout << "Database Full" << endl;
				}
				break;
			case 3://Remove Item
			{
				int i = 0;
				cout << endl << "****" << "Remove Item" << "****" << endl;
				cout << "Item description: ";
				scanf("%s", op3);
				list(op3);
				cout << "Enter SKU: ";
				cin >> i;
				remove(search(i));


			}
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
				flag = true;
				cout << endl << "****" << "New/Open Aid Database" << "****" << endl;
				cout << "Enter file name: ";
				cin >> name_file;
				ut.alocpy(filename, name_file);
				load();
				break;
			case 0:
				save();
				deallocate();
				break;
			}
		}
		cout << "Exiting Program!" << endl;
	}

	AidMan::~AidMan()
	{
		delete[] filename;
		filename = nullptr;
	}

};





