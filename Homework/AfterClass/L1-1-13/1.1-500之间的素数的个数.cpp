#include <bits/stdc++.h>
using namespace std;

int main()
{
	int flag = 1, a = 0;
	for (int i = 1; i <= 500; i++)
	{
		flag = 1;
		for (int j = 2; j <= pow(i , 0.5); j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			a++;
		}
	}
	cout << a - 1;
	return 0;
}
