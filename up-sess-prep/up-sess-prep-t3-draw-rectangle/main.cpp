/*
	rectangle max dimensions : 25 height, 80 width
*/

#include <iostream>
#include <iomanip>


void DrawRectangle(int height, int width, char symbol)
{
	std::cout << "The rectangle : \n";

	std::cout << std::setw((80 - width) / 2);	//to make the rectangle centered
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::cout << symbol;
		}

		std::cout << '\n';
		std::cout << std::setw((80 - width) / 2);	//to make the rectangle centered
	}
}

int main() {

	int height, width;
	char print_sym;

	std::cout << "Enter n : ";
	std::cin >> height;

	std::cout << "Enter m : ";
	std::cin >> width;
	
	std::cout << "Enter symbol : ";
	std::cin >> print_sym;

	if (height < 1 || height > 25 || width < 0 || width > 80) 
	{
		std::cout << "Error : wrong input, 0 <= height <= 25, 0 <= width <= 80";
		return -1;
	}

	DrawRectangle(height, width, print_sym);

	return 0;
}