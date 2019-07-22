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

/* i solved only the first two objectives of the given problem and they were
	7.a find if the triangles are equilateral
	7.b find if the triangles are upright by y,  meaning they have one side perpendicular to y-axis
		and the other two sides are equal (i don't remember if the definition required all sides to be equal, i.e. 7.a)
	7.c find the area of the intersecting part of the two triangles (?) and also if they are covering the requirements in 7.a and 7.b
*/
#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::sqrt;
using std::abs;
using std::pow;
using std::string;

//function attempting to more correctly determine if two double numbers are equal
bool EqualDoubles(double a, double b)
{
	const double EPSILON = 0.0001;
	return abs(a - b) < EPSILON;
}

struct Point2D
{
	double x;
	double y;

	double DistanceTo(Point2D other)
	{
		return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
	}
};

class Triangle2D
{
public:
	Triangle2D() = default;
	Triangle2D(const Triangle2D& other) = default;
	~Triangle2D() = default;
	Triangle2D& operator=(const Triangle2D& other) = default;

	void InitTriangle(Point2D& A_in, Point2D& B_in, Point2D C_in, string& name_in)
	{
		A = A_in;
		B = B_in;
		C = C_in;

		CalculateSides();
		name = name_in;
	}

	string GetName() const
	{
		return name;
	}

	// check if such triangle is possible to exist
	bool IsValid()
	{
		return (a + b > c) && (a + c > b) && (b + c > a);
	}

	// check if all the sides are equal
	bool IsEquilateral()
	{
		double eps = 0.00001;

		return EqualDoubles(a, b) && EqualDoubles(b, c);	// i.e. a == b and b == c
	}

	bool IsUprightByY()
	{
		return (EqualDoubles(a, b) && A.y < C.y)
			|| (EqualDoubles(a, c) && A.y < B.y)
			|| (EqualDoubles(b, c) && B.y < A.y);
	}

private:
	void CalculateSides()
	{
		c = A.DistanceTo(B);
		b = A.DistanceTo(C);
		a = B.DistanceTo(C);
	}

private:
	Point2D A;
	Point2D B;
	Point2D C;

	double c; // the side AB
	double b; // the side AC
	double a; // the side BC

	string name;
};

void InputTrianle(Triangle2D& triangle, string name)
{
	Point2D dummyA;
	Point2D dummyB;
	Point2D dummyC;

	cout << "Enter triangle" << name << " points : \n";

		cout << "first point (x, y) : ";
	cin >> dummyA.x >> dummyA.y;

	cout << "second point (x, y) : ";
	cin >> dummyB.x >> dummyB.y;

	cout << "third point (x, y) : ";
	cin >> dummyC.x >> dummyC.y;

	triangle.InitTriangle(dummyA, dummyB, dummyC, name);
}

void PrintTrianleInfo(Triangle2D& tr)
{
	if (!tr.IsValid())
		cout << "error : " << tr.GetName() << ", such triangle doesn't exist\n";

	cout << "triangle " << tr.GetName()
		<< (tr.IsEquilateral() ? "is" : "is not") << "equilateral and "
		<< (tr.IsUprightByY() ? "is" : "is not") << "upright by y-coordinate\n";

}

int main() {

	Triangle2D ABC;
	Triangle2D MNP;

	InputTrianle(ABC, "ABC");
	InputTrianle(MNP, "MNP");

	PrintTrianleInfo(ABC);
	PrintTrianleInfo(MNP);

	// bool ABC_exists = ABC.IsValid();
	// bool MNP_exists = MNP.IsValid();

	// bool ABC_is_equil = ABC.IsEquilateral();
	// bool MNP_is_equil = MNP.IsEquilateral();

	// bool ABC_is_upright_by_y = ABC.IsUprightByY();
	// bool MNP_is_upright_by_y = MNP.IsUprightByY();


	return 0;
}