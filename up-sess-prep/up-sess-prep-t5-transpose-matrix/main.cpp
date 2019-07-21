#include <iostream>
#include <iomanip>


void ReadMatrix(int* arr, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			std::cout << "arr[" << i << "][" << j << "] = ";
			std::cin >> arr[i * n + j];
		}
	}
}

void NullifyMatrix(int* arr, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			arr[i * n + j] = 0;
		}
	}
}

void PrintMaxtrix(const int* arr, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			std::cout << arr[i * n + j] << ' ';
		}
		std::cout << '\n';
	}
}

// transposing the matrix, without changing the original array 
void TransposeMatrix(const int* arr, const int n, int* transposed) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			// looping arr by columns and writing to transposed
			transposed[i * n + j] = arr[j * n + i];
		// 	
		//	arr[i*n + j] = transposed[j*n + i];
		}
	}
}

void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

// transposing the matrix itself
// going only through the elements over the main diagonal
int* Transpose(int* arr, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = i + 1; i < j && j < n; j++) 
		{
			Swap(arr[i*n + j], arr[j*n + i]);
		}
	}

	return arr;
}

int main() 
{
	int n;
	int a[100][100];
	int a_transposed[100][100];

	std::cout << "Enter n : ";
	std::cin >> n;

	ReadMatrix((int*)a, n);				//need to explicit cast to (int*)
	PrintMaxtrix((const int*)a, n);
	NullifyMatrix((int*)a_transposed, n);

	cout << "\nTransposeMatrix : \n";
	TransposeMatrix((const int*)a, n, (int*)a_transposed);
	PrintMaxtrix((const int*)a_transposed, n);

	cout << "\nTraspose : " << endl;
	Transpose((int*)a, n);
	PrintMaxtrix(a, n);

	std::cin.ignore();
	std::cin.get();

	return 0;
}