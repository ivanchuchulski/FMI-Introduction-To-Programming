//Ivan Chuchulski, fn : 62167
#pragma once



double Absolute(double a)
{
	return (a > 0) ? a : -a;
}

//task 2
double Calc(double a, double b, double eps, long int end)
{
	if (a <= 0)
		return -1.0;

	if (b <= 0)
		return -1.0;

	if (end < 2)
		return -1.0;

	double x_previous = a;			// X k - 2
	double x_current = b;			// X k - 1
	double x_next = 0.0;			// X k

	int k_counter = 2;

	while (true)
	{
		x_next = 0.2 * (x_current + (x_current / x_previous));
		k_counter++;

		if (k_counter > end)
			return -1.0;

		if (Absolute(x_next - x_current) < eps)
		{
			return x_next;
		}

		x_current = x_next;

	}
}


unsigned int GetDigitCount(int number)
{
	if (number == 1)
		return 1;

	int digit_count = 0;

	while (number != 0)
	{
		digit_count++;
		number /= 10;
	}

	return digit_count;
}

//task 3
bool NumCheck(long int num)
{
	unsigned int len = GetDigitCount(num);

	if (len < 3)
		return false;

	bool result = false;
	const size_t arr_size = 10;
	int digits [arr_size] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	while (num != 0)
	{
		int remainder = num % 10;
		digits[remainder]++;
		num /= 10;

		for (size_t i = 0; i < arr_size; i++)
		{
			if (digits[i] == 3)
			{
				result = true;
				return result;
			}

		}

	}

	return false;
}


struct VectorM 
{
	const size_t m_size_default = 3;
	int* m_Data;
	size_t m_Size;

	VectorM(long long size)
		:	m_Data(nullptr),
			m_Size((size > 0) ? size : m_size_default)
	{
		m_Data = new int[m_Size];
		NullOutData();
	}

	VectorM(const VectorM& other)
		:		m_Data(nullptr),
				m_Size(other.m_Size)
	{
		m_Data = new int[m_Size];
		NullOutData();

		for (size_t i = 0; i < m_Size; i++)
			m_Data[i] = other.m_Data[i];
	}

	~VectorM()
	{
		if (m_Data != nullptr)
		{
			delete[] m_Data;
		}
	}

	VectorM& operator=(const VectorM& other)
	{
		if (this != &other)
		{
			if (m_Data != nullptr)
				delete[] m_Data;

			m_Size = other.m_Size;
			m_Data = new int[m_Size];
			NullOutData();

			for (size_t i = 0; i < m_Size; i++)
				m_Data[i] = other.m_Data[i];
		}

		return *this;
	}

	void NullOutData()
	{
		for (size_t i = 0; i < m_Size; i++)
			m_Data[i] = 0;
	}

};

//task 1
int* scalarProduct(int* arr1, int* arr2, int m)
{
	if (arr1 == nullptr || arr2 == nullptr)
		return nullptr;

	if (m < 1)
		return nullptr;


	int* result_arr = new int[m];

	for (int i = 0; i < m; i++)
	{
		result_arr[i] = arr1[i] * arr2[i];
	} 

	return result_arr;
}

