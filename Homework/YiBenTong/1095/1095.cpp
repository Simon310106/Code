#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, sum = 0, a, b;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		a = i;
		while (a != 0)
		{
			b = a % 10;
			if (b == 1)
			{
				sum += 1;
			}
			a /= 10;
		}
	}
	cout << sum;
	return 0;
}
