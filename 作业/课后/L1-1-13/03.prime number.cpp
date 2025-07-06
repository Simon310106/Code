#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, flag = 1, p = 2;
	cin >> n;
	
	while (n > 0)
	{
		flag = 1;
		for (int j = 2; j <= sqrt(p); j++)
		{
			if (p % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			n--;
		}
		p++;
	}
	cout << p - 1;
	return 0;
}
