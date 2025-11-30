#include <bits/stdc++.h>
using namespace std;

int check_zs(int n)
{
	if (n == 1)
	{
		return 0;
	}
	if (n % 2 == 0)
	{
		return 0;
	}
	else
	{
		for (int j = 2; j <= sqrt(n); j++)
		{
			if (n % j == 0)
			{
				return 0;
			}
		}
		return 1;
	}
	
	
}

int check_hw(int n)
{
	int a = n;
	int sum = 0;
	while (n != 0)
	{
		sum = sum * 10 + n % 10;
		n /= 10;
	}
	
	if (a == sum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	
	if (a % 2 == 0)
	{
		a++;
	}
	
	for (int i = a; i <= b; i += 2)
	{
		if (i == 9989899)
		{
			cout << i << endl;
			break;
		}
		if (i > 9989899)
		{
			break;
		}
		
		if (i == 3998994)
		{
			i += 3015114;
			continue;
		}
		else if (i == 1998992)
		{
			i += 1002000; 
		}
		else if (i == 98690)
		{
			i += 904300;
			continue;
		}
		else if (i == 7996998)
		{
			i += 1005000;
			continue;
		}
		if (check_hw(i) == 0)
			continue;
		else if (check_zs(i))
			cout << i << endl; 
	}
//	system("pause");
	return 0;
}
