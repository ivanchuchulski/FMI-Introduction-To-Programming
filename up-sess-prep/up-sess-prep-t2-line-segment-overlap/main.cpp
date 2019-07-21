#include <iostream>
using namespace std;

struct Line {
	//line equation -> y = a*x + b
	double a;
	double b;
};

struct lineSegment{
	double x1;
	double y1;
	double x2;
	double y2;
};


bool Ox_findParallel(lineSegment A) {

	if (A.y1 == A.y2) {
		return true;
	}
	else {
		return false;
	}
}

bool Oy_findParallel(lineSegment A) {

	if (A.x1 == A.x2) {
		return true;
	}
	else {
		return false;
	}
}

int maximal(int a, int b) {
	if (a == b) {
		return a;
	}
	else {
		return (a > b) ? a : b;
	}
}
int minimal(int a, int b) {
	if (a == b) {
		return a;
	}
	else {
		return (a < b) ? a : b;
	}
}

int absoluteValue(int a) {
	if (a == 0) {
		return a;
	}

	else if (a < 0) {
		return (-a);
	}

}

void findOverlapping(lineSegment A, lineSegment B, bool A_par_Ox, bool B_par_Ox) {
	if (A_par_Ox == true && B_par_Ox == true && A.y1 == B.y1) {
		//handling if the points are equal
		//...
		
		//not complete
		if (maximal(A.x1, A.x2) > minimal(B.x1, B.x2)) {
			cout << "overlap : " << absoluteValue(maximal(A.x1, A.x2) - minimal(B.x1, B.x2)) << endl;
		}
		else {

		}
	}
	else {
		cout << "-1" << endl;
	}
}

int main() {
	
	/*
	Line line1 = { 5, 10 };
	Line line2 = { 3, 9 };

	cout << "line1 : " << line1.a << "x + " << line1.b << endl;
	cout << "line2 : " << line2.a << "x + " << line2.b << endl;
	*/

	lineSegment lineA;
	lineSegment lineB;

	lineA.x1 = 2;
	lineA.y1 = 2;
	lineA.x2 = 6;
	lineA.y2 = 2;

	lineB.x1 = 4;
	lineB.y1 = 2;
	lineB.x2 = 8;
	lineB.y2 = 2;

	bool A_parallel_with_Ox = Ox_findParallel(lineA);
	bool B_parallel_with_Ox = Ox_findParallel(lineB);

	findOverlapping(lineA, lineB, A_parallel_with_Ox, B_parallel_with_Ox);

	system("pause");
	return 0;
}
