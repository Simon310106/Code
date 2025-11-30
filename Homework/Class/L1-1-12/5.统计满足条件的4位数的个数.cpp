#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int ans = 0, g, s, b, q, m;
	cin >> n;
	
	for (int a, i=1; i <= n; i++)
	{
		cin >> a;
		g = a % 10;
		a /= 10;
		s = a % 10;
		a /= 10;
		b = a % 10;
		a /= 10;
		q = a % 10;
		m = g - q - b - s;
		if (m > 0)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
