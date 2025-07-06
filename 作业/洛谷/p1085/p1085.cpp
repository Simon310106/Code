#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c = 0, ans = 0;
	for (int i = 1; i < 8; i++)
	{
		cin >> a >> b;
		if (a + b > c)
		{
			c = a + b;
			ans = i;
		}
	}
	cout << ans;
	return 0;
}
