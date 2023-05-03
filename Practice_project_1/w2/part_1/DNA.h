#ifndef SDDS_DNA_H // replace with relevant names
#define SDDS_DNA_H

namespace sdds
{
	struct DNA
	{
		int numDna;
		char* dna = nullptr;
	};
	bool beginSearch(const char* filename);
	bool read(const char* subDNA);
	void sort();
	void displayMatches();
	void deallocate();
	void endSearch();

}
#endif