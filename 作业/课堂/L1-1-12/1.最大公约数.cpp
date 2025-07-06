#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	while (m != 0 && n != 0)
	{
		if (m > n)
		{
			m %= n;
		}
		else
		{
			n %= m;
		}
	}
	cout << m + n;
	return 0;
}
