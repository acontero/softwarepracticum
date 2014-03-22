#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(int arc, char *argv[])
{
	ifstream cFile;
	ifstream mf;
	string concatFile = argv[1];
	string mergedFile = argv[2];
		
	cout << "outputFile: " << concatFile <<endl;
	cout << "mergedFile: " << mergedFile <<endl;
			
	//reopen concat file to read
	cFile.open(concatFile);
    if (cFile.fail()){
        cout << "ERROR: failed re-opening concat file.\n";
        return -1;
    }

	//BUILD A MULTISET TO STORE VALUES FROM CONCAT FILE
	std::map<int,int> myList;
	int x;
	int listCount = 0;
    while(cFile >> x){
		if(myList.find(x) != myList.end()){
			myList[x]++;	
		} 
		else{
			myList.insert(std::pair<int,int>(x,1));
		}
		listCount++;
	}

	cout << "There are " << listCount << " elements in myList." <<endl;
	cFile.close();



	//NOW SEE IF ALL VALUES OF MERGED OUTPUT ARE IN myList
	mf.open(mergedFile);

    if (mf.fail()){
        cout << "ERROR: Opening merged output file failed.\n";
        return -1;
    }	

	int n;
    while(mf >> n){
		if(myList.find(n) == myList.end()){
			cout << "TEST FAILED: item not found in list!" <<endl ;
			cout << "The culprit is: " << n << endl;
			return -1;
		}
		else if(myList[n] <= 0){
			cout << "TEST FAILED: This item was not in the concatFile!" <<endl;
			cout << "The culprit is: " << n << endl;
			return -1;
		}
		else{
			myList[n]--;
		}
	}
	cout <<"TEST PASSED: mergedFile is the same as concatFile!"<<endl;
	return 0;
		
	mf.close();

}