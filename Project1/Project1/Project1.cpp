// Project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int arc, char *argv[])
{
	int token;
    int dataCount = 0;
	int count = 0;
    int startIndex;
	int endIndex;
	int minIndex;
    int walkerIndex;
    int temp;
    ifstream myfile;
    ofstream outFile;
    string inputFilename;
	string outputFilename;
    cout << "Please enter the name of the input file:" << endl;
    cin >> inputFilename;

    myfile.open(inputFilename);

    if (myfile.fail()){
        cout << "Input file opening failed.\n";
        return -1;
    }

    while(!myfile.eof()){
        myfile >> token;
        dataCount++;
    }
    cout << "Num of integers in file " << inputFilename << " = " << dataCount << endl;
	myfile.close();

    int *dataSorted = new int[dataCount];
  
	myfile.open(inputFilename);
    while(!myfile.eof()){
        myfile >> dataSorted[count];
        count++;
    }

    startIndex = 0;
    endIndex = dataCount -1;
    
    while(!(startIndex>=endIndex)){
        minIndex = startIndex;
        walkerIndex = startIndex + 1;
        while(!(walkerIndex > endIndex)){
            if (dataSorted[walkerIndex] < dataSorted[minIndex]) {
                minIndex = walkerIndex;
            }
            walkerIndex++;
        }
        temp = dataSorted[startIndex];
        dataSorted[startIndex] = dataSorted[minIndex];
        dataSorted[minIndex] = temp;
        startIndex++;
    }

    cout << "Please enter the name of the output file:" << endl;
    cin >> outputFilename;
    outFile.open(outputFilename);

    for (int i = 0; i < dataCount; i++)
        outFile << dataSorted[i] << " ";

    delete[] dataSorted;
    outFile.close();
    myfile.close();
    return 0;
}