// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant

/*Workshop 9 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.*/

#include <algorithm>
#include <future>
#include "process_data.h"

using namespace std;
namespace sdds_ws9 {

	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
		}
		avg /= divisor;
	}

	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}
	ProcessData::operator bool() const {
		return total_items > 0 && data && num_threads > 0 && averages && variances && p_indices;
	}



	ProcessData::ProcessData(std::string filename, int n_threads) {
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.


		ifstream bin_file(filename, std::ios::in | std::ios::binary);

		bin_file.read((char*)&total_items, sizeof(int));

		data = new int[total_items];
		for (auto i = 0; i < total_items; i++)
		{
			bin_file.read((char*)&data[i], sizeof(int));
			//cout << i << endl;
		}
		bin_file.close();

		std::cout << "Item's count in file '" << filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
			<< data[total_items - 3] << ", " << data[total_items - 2] << ", "
			<< data[total_items - 1] << "]\n";

		// Following statements initialize the variables added for multi-threaded 
		//   computation
		num_threads = n_threads;
		averages = new double[num_threads] {};
		variances = new double[num_threads] {};
		p_indices = new int[num_threads + 1] {};
		for (int i = 0; i < num_threads + 1; i++) {
			p_indices[i] = i * (total_items / num_threads);
		}


	}
	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	// TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the  
	//   function logic for the computation of average and variance by running the 
	//   function computeAvgFactor and computeVarFactor in multile threads. 
	// The function divides the data into a number of parts, where the number of parts is 
	//   equal to the number of threads. Use multi-threading to compute average-factor for 
	//   each part of the data by calling the function computeAvgFactor. Add the obtained 
	//   average-factors to compute total average. Use the resulting total average as the 
	//   average value argument for the function computeVarFactor, to compute variance-factors 
	//   for each part of the data. Use multi-threading to compute variance-factor for each 
	//   part of the data. Add computed variance-factors to obtain total variance.
	// Save the data into a file with filename held by the argument fname_target. 
	// Also, read the workshop instruction.

	int ProcessData::operator()(std::string file, double& val1, double& val2)
	{
		ofstream outputFile(file, std::ios::out | std::ios::binary);

		if (outputFile)
		{
			outputFile.write((const char*)(&total_items), sizeof(int));

			for (auto i = 0; i < total_items; i++)
			{
				outputFile.write((const char*)&data[i], sizeof(int));
			}
		}
		//std::vector<std::thread>  v_threar; better implementation 

		for (auto i = 0; i < num_threads; i++)
		{

			if (num_threads == 1)
			{
				std::thread th1(std::bind(computeAvgFactor, data, total_items, total_items, std::ref(averages[i])));
				th1.join();


				std::thread th2(std::bind(computeVarFactor, data, total_items, total_items, averages[i], std::ref(variances[i])));
				th2.join();



				val1 = averages[i];
				val2 = variances[i];
				averages[i] = 0;
				variances[i] = 0;
				return 0;

			}
			if (num_threads == 2)
			{
				int a = 0;
				int index = total_items / num_threads;
				int* copy = new int[index];

				for (auto i = 0; i < index; i++)
				{
					copy[a] = data[i];
					a++;
				}



				std::thread th1(std::bind(computeAvgFactor, copy, index, index, std::ref(averages[0])));
				th1.join();

				int j = a;
				a = 0;
				for (; j < total_items; j++)
				{
					copy[a] = data[j];
					a++;
				}

				std::thread th3(std::bind(computeAvgFactor, copy, index, index, std::ref(averages[1])));
				th3.join();

				delete[] copy;
				a = 0;
				index = total_items / num_threads;
				copy = new int[index];

				for (auto i = 0; i < index; i++)
				{
					copy[a] = data[i];
					a++;
				}
				val1 = (averages[0] + averages[1]) / 2;

				std::thread th2(std::bind(computeVarFactor, copy, index, index, val1, std::ref(variances[0])));
				th2.join();

				j = a;
				a = 0;

				for (; j < total_items; j++)
				{
					copy[a] = data[j];
					a++;
				}
				std::thread th4(std::bind(computeVarFactor, copy, index, index, val1, std::ref(variances[1])));
				th4.join();

				delete[] copy;
				val2 = (variances[0] + variances[1]) / 2;
				return 0;
			}
			else
			{

				int a = 0;
				int index = total_items / num_threads;
				int* copy = new int[index];
				int j = 0;
				for (; j < index; j++)
				{
					copy[a] = data[j];
					a++;
				}

				std::thread th1(std::bind(computeAvgFactor, copy, index, index, std::ref(averages[0])));
				th1.join();


				j = a;
				a = 0;
				int top = index * 2;

				for (; j < top; j++)
				{
					copy[a] = data[j];
					a++;
				}


				std::thread th3(std::bind(computeAvgFactor, copy, index, index, std::ref(averages[1])));
				th3.join();


				top = index * 3;
				a = 0;
				
				for (; j < top; j++)
				{
					copy[a] = data[j];
					a++;
				}

				std::thread th5(std::bind(computeAvgFactor, copy, index, index, std::ref(averages[2])));
				th5.join();

				a = 0;
				top = index * 4;
				for (; j < top; j++)
				{
					copy[a] = data[j];
					a++;
				}

				std::thread th7(std::bind(computeAvgFactor, copy, index, index, std::ref(averages[3])));
				th7.join();

				val1 = (averages[0] + averages[1] + averages[2] + averages[3]) / 4;

				delete[] copy;

				a = 0;
				index = total_items / num_threads;
				copy = new int[index];
				j = 0;
				for (; j < index; j++)
				{
					copy[a] = data[j];
					a++;
				}

				std::thread th2(std::bind(computeVarFactor, copy, index, index, val1, std::ref(variances[0])));
				th2.join();

				j = a;
				a = 0;
				top = index * 2;

				for (; j < top; j++)
				{
					copy[a] = data[j];
					a++;
				}

				std::thread th4(std::bind(computeVarFactor, copy, index, index, val1, std::ref(variances[1])));
				th4.join();

				top = index * 3;
				a = 0;
				for (; j < top; j++)
				{
					copy[a] = data[j];
					a++;
				}

				std::thread th6(std::bind(computeVarFactor, copy, index, index, val1, std::ref(variances[2])));
				th6.join();
				a = 0;
				top = index * 4;
				for (; j < top; j++)
				{
					copy[a] = data[j];
					a++;
				}

				std::thread th8(std::bind(computeVarFactor, copy, index, index, val1, std::ref(variances[3])));
				th8.join();

				val2 = (variances[0] + variances[1] + variances[2] + variances[3]) / 4;

				delete[] copy;
				return 0;
			}


		}
		return 0;

	};



}