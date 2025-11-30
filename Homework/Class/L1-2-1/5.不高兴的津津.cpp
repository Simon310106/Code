#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, m = 8;
	for (int i = 1; i <= 7; i++)
	{
		cin >> a >> b;
		if (a + b > 8)
		{
			m = min(m, i);
		}
	}
	cout << m;
	return 0;
}
