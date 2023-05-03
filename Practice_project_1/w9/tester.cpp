#include  <fstream>
#include <iostream>
#include "Text.h"
using namespace  std;
using namespace  sdds;

int  main(){
    Text T;
	Text Y;
	ifstream test("test.txt");
	test >> T;
	Y = T;
	Text Z = Y;
	T = Z;
	cout << "*" << T << "*" << endl;
	return 0;
}