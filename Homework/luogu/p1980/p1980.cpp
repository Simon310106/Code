#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x, i = 0, ans = 0, b, a = 0;
	cin >> n >> x;
	
	while (i < n)
	{
		i++;
		b = i;
		while (b != 0)
		{
			a = b % 10;
			b = b / 10;
			if (a == x)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
