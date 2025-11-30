#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, ans = 0;
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		int t = i, k = 0, flag = 0;
		while (t != 0)
		{
			k = t % 10;
			if (k != 7)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
				break;
			}
			t /= 10;
		}
		if (flag == 1 && i % 7 != 0)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
