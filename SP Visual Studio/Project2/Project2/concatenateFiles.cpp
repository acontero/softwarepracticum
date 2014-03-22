#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(int arc, char *argv[])
{
	ifstream myFirstFile;
	ifstream mySecondFile;
	ofstream cf;
	string file1 = argv[1];
	string file2 = argv[2];
	string concatFile = argv[3];
		
	cout << "file1: " << file1 <<endl;
	cout << "file2: " << file2 <<endl;
	cout << "outputFile: " << concatFile <<endl;
			
	myFirstFile.open(file1);

    if (myFirstFile.fail()){
        cout << "First input file opening failed.\n";
        return -1;
    }

	mySecondFile.open(file2);

    if (mySecondFile.fail()){
        cout << "Second input file opening failed.\n";
        return -1;
    }

	//open output file in order to write to it
	cf.open(concatFile);

	if (cf.fail()){
        cout << "First input file opening failed.\n";
        return -1;
    }
	cout << "Reached this point!"<<endl;
	//print numbers from first sorted file to the concat file, cf
	int a;
	int outputCount = 0;
    while(myFirstFile >> a){
		cf << a << " ";
		outputCount++;
	}
	cout << "Reached this point 2!"<<endl;
	//print numbers from second sorted file to the concat file
	int b;
	
    while(mySecondFile >> b){
		cf << b << " ";
		outputCount++;
	}

	cout << "Ouputted " << outputCount << " to the concat file." << endl;
	cf.close();
    myFirstFile.close();
	mySecondFile.close();	

	cout << "Finished concatenating the two files." <<endl;
	return 0;
}