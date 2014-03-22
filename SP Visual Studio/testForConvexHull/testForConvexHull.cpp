// testForConvexHull.cpp : Defines the entry point for the console application.

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;

static int tsize, csize;

struct Coord {

	int x, y;

	Coord() {
		x = 0;
		y = 0;
	}

	Coord(int a, int b) {
		x = a;
		y = b;
	} 
	~Coord() {}

}; 

bool testConvexHull(Coord* truech, Coord* checkch, int tsize, int csize) {
	cout << "True CH: " << tsize << endl;
	cout << "Checking CH: " << csize << endl;
	if (tsize != csize) {
		cout << "TEST FAILED: This convex hull does not have the correct number of elements!." << endl;
		return false;
	}
	for (int i = 0; i < tsize; i++){
		if (truech[i].x != checkch[i].x ){
			cout << "Fails at True CH X= " << truech[i].x << " and Check CH X = " <<checkch[i].x <<endl;
			return false;
		}
		if(truech[i].y != checkch[i].y){
			cout << "Fails at True CH Y= " << truech[i].y << " and Check CH Y = " <<checkch[i].y <<endl;
			return false;
		}
	}
	return true;

}

int getSize(string name) {
	int i = 0;
	fstream file(name);
	int x, y;
	while (file >> x) {
		file >> y;
		cout << x << "," << y << endl;
		i++;
	}
	cout << " " << endl;
	file.close();
	return i;
}

Coord* createList(string filename, int size) {
	fstream f(filename);
	Coord* c = new Coord[size];
	int x, y;
	for (int i = 0; i < size; i++) {
		f >> x;
		f >> y;
		c[i] = Coord(x, y);
	}
	return c;
} 

int main(int argc, char* argv[])
{
	tsize = getSize(argv[1]);
	csize = getSize(argv[2]);
	Coord* truechList = createList(argv[1],tsize);
	Coord* checkchList = createList(argv[2],csize);

	bool equal = testConvexHull(truechList, checkchList, tsize, csize);
	if (equal)
		cout << "TEST PASSED: Valid convex hull." << endl;
	else
		cout << "TEST FAILED: Convex hull invalid." << endl;
		

	delete[] truechList;
	delete[] checkchList;
	return 0;
}

