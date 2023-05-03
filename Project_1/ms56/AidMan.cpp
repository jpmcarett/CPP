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
	using namespace std;
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
				option = ut.getint(0, 1, " 1 - Yes!\n0 - Exit \n > ");
				if (option == 1)
				{
					ofstream ofs(filename);
				}
			}
			else
			{
				while (!ifs.eof())
				{
					flag = true;
					bool flag2 = false;
					char value = ifs.peek();
					int val = (int)value - 48;
					if ((val > 0) && (val < 4))// persihable
					{
						iproductArray[track] = new Perishable;
						flag2 = true;
					}
					if ((val > 3) && (val < 10))// Item
					{
						iproductArray[track] = new Item;
						flag2 = true;
					}
					if (flag2 == false)
					{
						ifs.setstate(ios::badbit);
					}
					else
					{
						if (iproductArray[track])
						{
							iproductArray[track]->load(ifs);
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
		int j = 0;
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
		for (k = 0; k < track; k++)
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
				iproductArray[track]->read(cin);
			}
			else//Item
			{
				iproductArray[track]->read(cin);
			}
			cout << endl;
		}
		else //if (searching==-1)
		{
			// problem with this part you need it in ms52 but i ms54 is a problem
		//	cout << "Sku: " << sku << " is already in the system, try updating quantity instead.\n\n";
		}
		return searching;
	}

	void AidMan::remove(int index)
	{
		int tra = 0;
		delete iproductArray[index];
		iproductArray[index] = nullptr;
		for (tra = index; tra <= track; tra++)
		{
			iproductArray[tra] = iproductArray[tra + 1];
		}
		delete iproductArray[track];
		iproductArray[track] = nullptr;
		track--;
		save();
	}

	void AidMan::update(int option, int index)
	{
		int value = 0;
		if (option == 0)
		{
			cout << "Aborted!\n\n";
		}
		if (((iproductArray[index]->qty() == iproductArray[index]->qtyNeeded()) && option == 1))
		{
			cout << "Quantity Needed already fulfilled!\n\n";
		}
		else
		{
			if (option == 1)
			{
				value = ut.getint(1, iproductArray[index]->qtyNeeded(), "Quantity to add: ");
				iproductArray[index]->operator+=(value);
				cout << value << " items added!\n\n";
			}
			if (option == 2)
			{
				value = ut.getint(1, iproductArray[index]->qtyNeeded(), "Quantity to reduce: ");
				if (value == 0)
				{
					cout << "Quaintity on hand is zero!\n";
				}
				else
				{
					iproductArray[index]->operator-=(value);
					cout << value << " items removed!\n\n";
				}
			}
		}
	}

	void AidMan::sort()
	{
		int i, j = 0;
		iProduct* temp{};
		int value1, value2 = 0;

		for (i = 0; i < track; i++)
		{
			for (j = i + 1; j < track; j++)
			{
				value1 = iproductArray[j]->qtyNeeded() - iproductArray[j]->qty();
				value2 = iproductArray[i]->qtyNeeded() - iproductArray[i]->qty();
				if (value1 > value2)
				{
					temp = iproductArray[i];
					iproductArray[i] = iproductArray[j];
					iproductArray[j] = temp;

				}
			}
		}
		//delete temp; temp is saving the addrres of the last position, if you deleter here, 
		//temp = nullptr;
		cout << "Sort completed!\n\n";
	}

	void AidMan::ship()
	{
		int i = 0;
		int cont = 0;
		ofstream ofst("shippingOrder.txt", ofstream::out);
		ofst << "Shipping Order, Date: ";
		ofst << Date();
		ofst << "\n ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry\n";
		ofst << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
		for (i = 0; i < track; i++)
		{
			if (iproductArray[i]->qty() == iproductArray[i]->qtyNeeded())
			{
				ofst.width(4);
				ofst.fill(' ');
				ofst << (cont + 1);
				ofst << " | ";
				iproductArray[i]->linear(true);
				iproductArray[i]->display(ofst);
				ofst << endl;
				cont++;
				remove(i);
				i--;
			}
		}
		ofst << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
		cout << "Shipping Order for " << cont << " times saved!\n\n";
	}
	void AidMan::run()
	{
		int i = 0;
		int out = 30;
		int opt2 = 0;
		bool flag = false;
		char name_file[50];
		char op3[10];
		int index = 0;
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
			{
				cout << endl << "****" << "Add Item" << "****" << endl;
				if (track <= sdds_max_num_items)
				{

					opt2 = ut.getint(0, 2, "1 - Perishable\n2- Non-Perishable\n-----------------\n0- Exit\n> ");
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
			}
			case 3://Remove Item
			{
				i = 0;
				cout << endl << "****" << "Remove Item" << "****" << endl;
				cout << "Item description: ";
				scanf("%s", op3);
				list(op3);
				cout << "Enter SKU: ";
				cin >> i;
				index = search(i);
				cout << "Following item will be removed: \n";
				iproductArray[index]->linear(false);
				iproductArray[index]->display(cout);
				cout << "\nAre you sure?" << endl;
				cout << "1- Yes!\n0- Exit\n> ";
				cin >> i;
				if (i == 1)
				{
					remove(index);
					cout << "Item removed!" << endl << endl;
				}
				else
				{
					//do nothing 
				}

			}
			break;
			case 4:
			{
				i = 0;
				cout << endl << "****" << "Update Quantity" << "****" << endl;
				cout << "Item description: ";
				scanf("%s", op3);
				list(op3);
				cout << "Enter SKU: ";
				cin >> i;
				opt2 = search(i);
				if (opt2 < 0)
				{
					cout << "SKU not found!\n";
				}
				else
				{
					i = ut.getint(0, 2, "1- Add\n2- Reduce\n0- Exit\n> ");
					//cout << "1- Add\n2- Reduce\n0- Exit\n> ";
					//cin >> i;
					update(i, opt2);
				}

				break;
			}
			case 5:
				cout << endl << "****" << "Sort" << "****" << endl;
				sort();
				break;
			case 6:
				cout << endl << "****" << "Ship Items" << "****" << endl;
				ship();
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





