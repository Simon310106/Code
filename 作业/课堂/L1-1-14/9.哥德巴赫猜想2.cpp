#include <bits/stdc++.h>
using namespace std;

int main()
{
	for (int n = 2; n <= 100; n += 2)
	{
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
				cout << n << "=" << i << "+" << n - i << endl;
				break;
			}
		}
	}
	return 0;
}
