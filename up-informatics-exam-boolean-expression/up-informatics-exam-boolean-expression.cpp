#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_set>

using namespace std;

bool Expr(const bool a, const bool b, const bool c)
{
	return a || !b && c;
}

// a || !b && c; && has a higher precedence than ||
bool Boolean(const bool a, const bool b, const bool c)
{
	bool not_b;
	bool not_b_and_c;

	//!b
	switch (b)
	{
		case true: not_b = false; break;
		case false: not_b = true; break;
	}

	//!b && c
	switch (c)
	{
		case false: not_b_and_c = false; break;
		case true:
		{
			switch (not_b)
			{
				case false: not_b_and_c = false; break;
				case true: not_b_and_c = true; break;
			}
		}
	}

	//a || not_b_and_c
	switch (a)
	{
		case false:
		{
			switch (not_b_and_c)
			{
				case false: return false;
				case true: return true;
			}
		}
		case true: return true;
	}
}

//wrong, this computes : (a || !b) && c
bool Booleanv2(const bool a, const bool b, const bool c)
{
	bool not_b;
	bool a_or_not_b;

	//!b
	switch (b)
	{
	case true: not_b = false; break;
	case false: not_b = true; break;
	}

	//a || not_b
	switch (a)
	{
	case false:
	{
		switch (not_b)
		{
		case false: a_or_not_b = false; break;
		case true: a_or_not_b = true; break;
		}
	}
	case true: a_or_not_b = true;
	}

	//(...) && c
	switch (c)
	{
	case false: return false;
	case true:
	{
		switch (a_or_not_b)
		{
		case false: return false;
		case true: return true;
		}
	}
	}


}


int main() {

	ios_base::sync_with_stdio(false);

	cout << Expr(0, 0, 0) << ' ' << Boolean(0, 0, 0) << ' ' << Booleanv2(0, 0, 0) << '\n';
	cout << Expr(1, 0, 0) << ' ' << Boolean(1, 0, 0) << ' ' << Booleanv2(1, 0, 0) << '\n';
	cout << Expr(0, 1, 0) << ' ' << Boolean(0, 1, 0) << ' ' << Booleanv2(0, 1, 0) << '\n';
	cout << Expr(0, 0, 1) << ' ' << Boolean(0, 0, 1) << ' ' << Booleanv2(0, 0, 1) << '\n';
	cout << Expr(1, 1, 0) << ' ' << Boolean(1, 1, 0) << ' ' << Booleanv2(1, 1, 0) << '\n';
	cout << Expr(1, 0, 1) << ' ' << Boolean(1, 0, 1) << ' ' << Booleanv2(1, 0, 1) << '\n';
	cout << Expr(0, 1, 1) << ' ' << Boolean(0, 1, 1) << ' ' << Booleanv2(0, 1, 1) << '\n';
	cout << Expr(1, 1, 1) << ' ' << Boolean(1, 1, 1) << ' ' << Booleanv2(1, 1, 1) << '\n';


	system("pause");
	return 0;
}