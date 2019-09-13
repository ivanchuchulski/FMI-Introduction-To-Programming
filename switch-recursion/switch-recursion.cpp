#include <iostream>
#include <cstdlib>

void R(int r)
{
	switch (!(r += (r < 0) - (r > 0)))
	{
		case 0 : 
			R(-r);

		default:
			std::cout << ' ' << r;
	}
}

int main()
{
	R(5);
	std::exit(0);
}