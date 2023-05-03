#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <iomanip>
#include "DNA.h"
#include "cStrTools.h"


namespace sdds
{
	const int MAX_VALUE_STRUCT = 10;
	FILE* fptr;
	DNA* Dna_data = nullptr;
	int number = 0;// number of the data;
	bool beginSearch(const char* filename)
	{

		bool flag = false;
		fptr = fopen(filename, "r");
		if (fptr != NULL)
		{
			flag = true;





		}
		return flag;
	}


	bool read(const char* subDNA)
	{
		Dna_data = new DNA[MAX_VALUE_STRUCT];
		int lent_dna = 0;
		int tempin;
		char tempchar[100000];
		int number_2 = 0;
		
		int i = 0;
		bool flag = false;
		int size_subDNA=0;
		while (fscanf(fptr, "%d,%s\n", &tempin, tempchar) != EOF)
		{
			lent_dna = strLen(tempchar); // size of the input from de file
			size_subDNA = strLen(subDNA);
			i++;
			if (strStr(tempchar, subDNA)!=0)
			{
				
				Dna_data[number].dna = new char[lent_dna + 1];
				Dna_data[number].numDna = tempin;
				Dna_data[number].dna = tempchar;
				number++;
				flag = true;
				lent_dna = 0;
				std::cout << tempin << " -------" << tempchar << std::endl;



			}
			//if (number == MAX_VALUE_STRUCT)
			//{
			//	// new dinamic struct array
			//	DNA* temporal = nullptr;
			//	temporal = new DNA[number];
			//	for (i = 0; i < number; i++)
			//	{
			//		Dna_data[i] = temporal[i];
			//	}
			//	delete[] Dna_data;
			//	Dna_data = nullptr;
			//	number_2 += 100;
			//	Dna_data = new DNA[number_2];
			//	for (i = 0; i < number; i++)
			//	{
			//		Dna_data[i] = temporal[i];
			//	}
			//	delete[] temporal;
			//	temporal = nullptr;
			//}
			//
			
		}
		return flag;
	}
	void sort()
	{
		//temporal = new DNA[MAX_VALUE_STRUCT];

		int i, j, m;
		int num_out;
		int num_in;
		int size_int = 0;
		int size_out = 0;
		int char_out = 0;
		int char_in = 0;
		char* temp_char_out = nullptr;
		for (i = 0; i < number; i++) {
			m = i;
			for (j = i + 1; j < number; j++)
				if (Dna_data[j].numDna < Dna_data[m].numDna) {
					m = j;
				}
			if (m != i) {


				// copy the first position			
				num_out = Dna_data[i].numDna;
				size_out = strLen(Dna_data[i].dna);
				temp_char_out =new char(size_out+1);
				//temp_char_out = Dna_data[i].dna;
				strCpy(temp_char_out, &*Dna_data[i].dna);
				delete[] &Dna_data[i].numDna;
				delete[] &Dna_data[i].dna;
				//Dna_data[i].numDna = nullptr;


				num_in= Dna_data[m].numDna;
				char_out = strLen(Dna_data[m].dna);
				//size_out = strLen(Dna_data[m].dna);

				
				//delete[] Dna_data[m].dna;
				//Dna_data[m].dna = nullptr;


				temp_char_out = new char(char_out + 1);
				//strCpy(temp_char,Dna_data[i].dna);
				//move the second info
				/*
				num_in= Dna_data[m].numDna;
				delete[] & Dna_data[i];
				Dna_data[i] = nullptr;
				Dna_data[i].numDna = num_in;
				char_in = strLen(Dna_data[m].dna);

				
				Dna_data[i].dna = nullptr;
				Dna_data[i].dna = new char[char_in + 1];
				strCpy(	Dna_data[i].dna, Dna_data[m].dna);
				Dna_data[m].numDna = num_out;

				delete[] Dna_data[m].dna;
				Dna_data[m].dna = nullptr;
				Dna_data[m].dna = new char[char_out + 1];
				Dna_data[m].dna = temp_char;
				
				delete[] temp_char;
				temp_char = nullptr;*/
			}
		}
	}
	void displayMatches()
	{

	}
	void deallocate()
	{

	}
	void endSearch()
	{
		fclose(fptr);

	}
}