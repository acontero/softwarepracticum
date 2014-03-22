#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int arc, char *argv[])
{
    ifstream myFirstFile;
    string filename1 = argv[1];
   
	myFirstFile.open(filename1);

    if (myFirstFile.fail()){
        cout << "ERROR: Failed to open input file.\n";
        return -1;
    }

	int x;
	int y;
	myFirstFile >> x;
	while(!myFirstFile.eof()){
		myFirstFile >> y;
		if(y<x){
			cout << "TEST FAILED: The input file is not sorted!\n" << endl;
			return -1;
		}
		int temp = y;
		x = temp;
    }

	cout << "TEST PASSED: The input file is sorted.\n" << endl;
	
	myFirstFile.close();
	return 0;
}