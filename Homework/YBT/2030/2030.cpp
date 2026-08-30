#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	int flag = 0;
	cin >> a >> b;
	
	for (int i = a; i <= b; i++)
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
			cout << i << endl;
		}
	}
	return 0;
}
