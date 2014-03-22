// Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int arc, char *argv[])
{
    ifstream myFirstFile;
	ifstream mySecondFile;
    ofstream outFile;
    string filename1;
    cout << "Please enter the name of the first input file:" << endl;
    cin >> filename1;
	string filename2;
    cout << "Please enter the name of the second input file:" << endl;
	cin >> filename2;
    
	myFirstFile.open(filename1);

    if (myFirstFile.fail()){
        cout << "First input file opening failed.\n";
        return -1;
    }

	mySecondFile.open(filename2);

    if (mySecondFile.fail()){
        cout << "Second input file opening failed.\n";
        return -1;
    }

	//Make sure each file is sorted before proceeding with the program.

	int x;
	int y;
	myFirstFile >> x;
	while(!myFirstFile.eof()){
		myFirstFile >> y;
		if(y<x){
			cout << "The first input file is not sorted!" << endl;
			return -1;
		}
		int temp = y;
		x = temp;
    }

	int w;
	int z;
	mySecondFile >> w;
	while(!mySecondFile.eof()){
		mySecondFile >> z;
		if(z<w){
			cout << "The second input file is not sorted!" << endl;
			return -1;
		}
		int temp2 = z;
		w = temp2;
    }

	cout << "Things are looking good!" << endl;
	
	myFirstFile.close();
	mySecondFile.close();


	//reopen the files for use
	myFirstFile.open(filename1);

    if (myFirstFile.fail()){
        cout << "First input file opening failed.\n";
        return -1;
    }

	mySecondFile.open(filename2);

    if (mySecondFile.fail()){
        cout << "Second input file opening failed.\n";
        return -1;
	}

	string outputFilename;
    cout << "Please enter the name of the output file:" << endl;
    cin >> outputFilename;
    outFile.open(outputFilename);

	int a;
	int b;
	myFirstFile >> a;
	mySecondFile >> b;
	int outputCount = 0;
	//print numbers from both input files to output file in order
    while(!myFirstFile.eof() && !mySecondFile.eof()){
		if(a<=b){
			outFile << a << " ";
			myFirstFile >> a;
		}
		else{
			outFile << b << " ";
			mySecondFile >> b;
		}
		outputCount++;

	}

	//print any remaining values from first input file to output file
	while(!myFirstFile.eof()){
		outFile << a << " ";
		myFirstFile >> a;
		outputCount++;
	}
		
	//print any remaining values from second input file to output file
	while(!mySecondFile.eof()){
		outFile << b << " ";
		mySecondFile >> b;
		outputCount++;
	}

	cout << "Ouputted " << outputCount << " to the output file." << endl;
	outFile.close();
    myFirstFile.close();
	mySecondFile.close();
    return 0;
}

