#include <bits/stdc++.h>
using namespace std;

int n, flag[1050];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j % i == 0)
			{
				if (flag[j - 1] == 0)
				{
					flag[j - 1] = 1;
				}
				else if (flag[j - 1] != 0)
				{
					flag[j - 1] = 0;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i - 1] == 1)
		{
			cout << i << ' ';
		}
	}
	return 0;
}
