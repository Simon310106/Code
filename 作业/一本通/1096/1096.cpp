#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l, r, sum = 0, a, b;
	cin >> l >> r;
	
	for (int i = l; i <= r; i++)
	{
		a = i;
		while (a != 0)
		{
			b = a % 10;
			if (b == 2)
			{
				sum += 1;
			}
			a /= 10;
		}
	}
	cout << sum;
	return 0;
}
