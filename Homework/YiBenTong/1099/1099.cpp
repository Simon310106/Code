#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, flag = 0, a = 0, ans = 0;
	cin >> n;
	
	for (int i = 2; a <= n; i++)
	{
		flag = 0;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			a++;
			if (a == n)
			{
				ans = i;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
