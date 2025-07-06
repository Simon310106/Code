#include <bits/stdc++.h>
using namespace std;

int a[10500], m, l, s, e, b;
int main()
{
	cin >> l >> m;
	for (int i = 0; i <= l; i++)
	{
		a[i] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> s >> e;
		while (s <= e)
		{
			a[s++] = 0;
		}
	}
	for (int i = 0; i <= l; i++)
	{
		if (a[i] == 1)
		{
			b++;
		}
	}
	cout << b;
	return 0;
}
