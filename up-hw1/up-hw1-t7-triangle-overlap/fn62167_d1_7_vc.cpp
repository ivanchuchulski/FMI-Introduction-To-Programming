/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Ivan Chuchulski
* @idnumber 62167
* @task 7
* @compiler VC
*
*/
#include <iostream>
#include <cmath>
using namespace std;
// distance between two points
double calculateDistance(double Ax, double Ay, double Bx, double By) {
	return sqrt(pow((Ax - Bx), 2) + pow((Ay - By), 2));
}
bool triangleInequality(double a, double b, double c) {
	if (a + b > c && b + c > a && a + c > b) {
		return true;
	}
	else {
		return false;
	}
}
bool equilateralTriangle(double a, double b, double c) {
	//precision
	double epsilon = 0.00001;
	if ( abs(a - b) < epsilon && abs(b - c) < epsilon ) {
		return true;
	}
	else {
		return false;
	}
}
bool isUpright(double Ay, double By, double Cy) {
	if (((Ay == By) && (Cy > Ay)) ||
		((By == Cy) && (Ay > By)) ||
		((Ay == Cy) && (By > Ay))) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	//triangle ABC
	double Ax, Ay;
	double Bx, By;
	double Cx, Cy;
	//triangle MNP
	double Mx, My;
	double Nx, Ny;
	double Px, Py;
	//input of the coordinates
	cout << "Enter point A coordinates (x,y) : ";
	cin >> Ax >> Ay;
	cout << "Enter point B coordinates (x,y) : ";
	cin >> Bx >> By;
	cout << "Enter point C coordinates (x,y) : ";
	cin >> Cx >> Cy;
	cout << "Enter point M coordinates (x,y) : ";
	cin >> Mx >> My;
	cout << "Enter point N coordinates (x,y) : ";
	cin >> Nx >> Ny;
	cout << "Enter point P coordinates (x,y) : ";
	cin >> Px >> Py;
	//calculating the lenght of the sides
	double AB = calculateDistance(Ax, Ay, Bx, By);
	double BC = calculateDistance(Bx, By, Cx, Cy);
	double AC = calculateDistance(Ax, Ay, Cx, Cy);
	double MN = calculateDistance(Mx, My, Nx, Ny);
	double NP = calculateDistance(Nx, Ny, Px, Py);
	double MP = calculateDistance(Mx, My, Px, Py);
	//check if the triangles exist
	bool ABC_exist = triangleInequality(AB, BC, AC);
	bool MNP_exist = triangleInequality(MN, NP, MP);
	if (ABC_exist == false && MNP_exist == false) {
		cout << "Both triangles do not exist" << endl;
		//system("pause");
		//return 0;
	}
	else if (ABC_exist == false && MNP_exist == true) {
		cout << "Triangle ABC does not exist" << endl;
		//system("pause");
		//return 0;
	}
	else if (ABC_exist == true && MNP_exist == false) {
		cout << "Triangle MNP does not exist" << endl;
		//system("pause");
		//return 0;
	}
	else;
	//check if the triangles are equilateral
	bool equilateral_ABC = equilateralTriangle(AB, BC, AC);
	bool equilateral_MNP = equilateralTriangle(MN, NP, MP);
	if (equilateral_ABC == false && equilateral_MNP == false) {
		cout << "Both triangles are not equilateral" << endl;
	}
	else if (equilateral_ABC == false && equilateral_MNP == true) {
		cout << "Triangle ABC is not equlateral, triangle MNP is" << endl;
	}
	else if (equilateral_ABC == true && equilateral_MNP == false) {
		cout << "Triangle ABC is equilateral but MNP is not" << endl;
	}
	else {
		cout << "Both triangles are equilateral" << endl;
	}
	//check if the triangles are upright
	bool upright_ABC = isUpright(Ay, By, Cy);
	bool upright_MNP = isUpright(My, Ny, Py);
	if (upright_ABC == false && upright_MNP == false) {
		cout << "Both triangles are not upright" << endl;
	}
	else if (upright_ABC == false && upright_MNP == true) {
		cout << "Triangle ABC is not upright, triangle MNP is" << endl;
	}
	else if (upright_ABC == true && upright_MNP == false) {
		cout << "Triangle ABC is upright, but MNP is not" << endl;
	}
	else {
		cout << "Both triangles are upright" << endl;
	}
	system("pause");
	return 0;
}