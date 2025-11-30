#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	for (int i = 3; i <= n/2; i+=2)
	{
		int flag1 = 1, flag2 = 1;
		for (int j = 3; j <= sqrt(i); j += 2)
		{
			if (i % j == 0)
			{
				flag1 = 0;
				break;
			}
		}
		if (flag1 == 1)
		{
			for (int j = 3; j <= pow (n - i, 0.5); j += 2)
			{
				if ((n - i) % j == 0)
				{
					flag2 = 0;
					break;
				}
			}
		}
		if (flag2 == 1 && flag1 == 1)
		{
			cout << i << "+" << n - i;
			return 0;
		}
	}
	return 0;
}
