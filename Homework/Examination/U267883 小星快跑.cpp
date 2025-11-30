#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, t = 0, ans = 0, d, e, f, g, h;
	cin >> a >> b >> c;
	d = a;
	e = b;
	f = c;
	
	while (a != 0 && b != 0)
	{
		if (a > b)
		{
			a %= b;
		}
		else
		{
			b %= a;
		}
	}
	t = a + b;
	ans = d * e / t;
	g = ans;
	
	while (ans != 0 && c != 0)
	{
		if (ans > c)
		{
			ans %= c;
		}
		else
		{
			c %= ans;
		}
	}
	h = ans + c;
	ans = g * f / h;
	cout << ans;
	return 0;
}
