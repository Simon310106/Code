#include <bits/stdc++.h>
using namespace std;

int main()
{
	int flag = 1;
	for (int i = 100; i <= 200; i++)
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
			cout << i << " ";
		}
	}
	return 0;
}
