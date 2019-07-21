//Данием Димитров Димитров 62121


int pow(int n, int power)
{
	int result = 1;
	if (power == 0)
	{
		return 1;
	}
	for (int i = 0; i < power; i++)
	{
		result *= n;
	}
	return result;
}

int len(char* a)
{
	int i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return i;
}

int charToAscii(char a)
{
	a = a - '0';
	return a;
}

bool IsCorrect(char* a)
{
	int length = len(a);
	bool correct = false;
	for (int i = 0; i < length - 2; i++)
	{
		if ((charToAscii(a[i]) == charToAscii(a[i + 1] - 1)) && (charToAscii(a[i]) == charToAscii(a[i + 2] - 2)))
		{
			correct = true;
			break;
		}
	}
	return correct;
}

bool CheckHeapDate(char* a)
{
	int length = len(a);
	if (length != 7)
	{
		return false;
	}
	if (a[6] != '.')
	{
		return false;
	}
	if (a[5] != 'g')
	{
		return false;
	}
	if (a[4] != ' ')
	{
		return false;
	}
	for (int i = 0; i < 4; i++)
	{
		if (a[i] < '0' || a[i] >'9')
		{
			return false;
		}
	}
	int result = 0;
	int power = 3;
	for (int i = 0; i < 3; i++)
	{
		result += charToAscii(a[i])*pow(10, power--);
	}
	result += charToAscii(a[3]);
	if (result % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	return true;
}


bool areSimilar(int* a, int* b, int m, int n)
{
	bool similar = false;
	int biggernumber;
	if (m>n)
	{
		biggernumber = m;
		for (int i = 0; i < m; i++)
		{
			similar = false;
			for (int j = 0; j < n; j++)
			{
				if (a[i] == b[j])
				{
					similar = true;
					break;
				}
			}

			if (similar == false)
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		biggernumber = n;
		for (int i = 0; i < n; i++)
		{
			similar = false;
			for (int j = 0; j < m; j++)
			{
				if (b[i] == a[j])
				{
					similar = true;
					break;
				}

			}
			if (similar == false)
			{
				return false;
			}

		}
		return true;

	}

	return true;
}

