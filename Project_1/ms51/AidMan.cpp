/* ------------------------------------------------------
Name: Juan Pablo Martinez Carett
Email:jpmartinez-carett@myseneca.ca
Student ID: 112494216
Date:09/04/2022
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
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
		if (filename==nullptr)
		{
			cout << "Data file: No file" << endl;
		}
		else
		{
			cout << "Data file: " << filename << endl;
		}
		cout << "---------------------------------" << endl;
		option =m_menu.run();
		return option;
	}

	void AidMan::
	save()
	{
		int i = 0;
		if ((filename!=nullptr)&&(track!=0) )
		{
			ofstream ofs(filename,ofstream::out);
			for ( i=0;i<track;i++)
			{
				iproductArray[i]->save(ofs);
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
		if ( track != 0)
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
		if (filename!=nullptr)
		{
			ifstream ifs;
			ifs.open (filename);
			if (!ifs)
			{
				cout << "Failed to open " << filename << " for reading!" << endl;
				cout << "Would you like to create a new data file?" << endl;
				cout << "1- Yes!\n0- Exit \n>";
				cin >> option; // you need yo used get int hre
				if (option==1)
				{
					ofstream ofs(filename);
				}
			}
			else
			{
				flag = true;
				while (!ifs.eof())// need to read until the last sentences
				{
					//iProduct* Per=nullptr;
					bool flag2 = false;
					char value = ifs.peek();
					int val = (int)value-48;
					
					if ((val>0)&&(val <4))// persihable
					{
						iproductArray[track] = new Perishable;
						iproductArray[track]->load(ifs);
						flag2 = true;
						
					}
					if ((val>3)&& (val<10))// Item
					{
						iproductArray[track] = new Item;
						iproductArray[track]->load(ifs);
					
						flag2 = true;
						
					}
					if (flag2==false)
					{
						ifs.setstate(ios::badbit);
					}
					else
					{
						if (flag2)// you are cheking this part in the bad way
						{
							//iproductArray[track] = (Per);
							//track++;
						}
						else
						{
						//	delete[] Per;
							//Per = nullptr;

						}
						track++;
					}
				}
			}
			
		}
		cout << track << " records loaded!" << endl<<endl;
		return flag;
	}

	int AidMan::list(const char* sub_desc)
	{
		int k = 0;
		int j = 0;//variable created for the compiler
		char va;
		int opt = 0;
		if (sub_desc==nullptr)
		{
			cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			for (k=0; k < track; k++)
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
			cin.get(va);// change that
			opt = (int)va - 49;
		}
			if ((opt>0)&&(opt<=track))
			{
				iproductArray[opt]->linear(false);
				iproductArray[opt]->display(cout);

			}
			cout << endl;
		
		return opt;
	}

	void AidMan::run()
	{
		int out = 30;
		//int k = 0;
		bool flag = false;
		char name_file[50];
		while (out != 0)
		{
			out = menu();
			if ((filename==nullptr)||(flag==false))
			{
				out = 7;
			}
			switch (out) {
			case 1:
				//variables for this function
			//	k = 1;
				cout << endl << "****" << "List Items" << "****" << endl ;
				if (track != 0)
				{
					//k =list(nullptr);
					list(nullptr);
				}
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
				flag=true;
				cout << endl << "****" << "New/Open Aid Database" << "****" << endl;
				cout << "Enter file name: ";
				cin >> name_file;
				ut.alocpy(filename, name_file);
				load();
				break;
			case 0:
				deallocate();
				// save you information, need to created a method for this part 
				break;
			}
		}
		cout <<"Exiting Program!"<<endl;
	}

	AidMan::~AidMan()
	{
		delete[] filename;
		filename = nullptr;
	}
	
	};





