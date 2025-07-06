#include <bits/stdc++.h>
using namespace std;

int a[1050], b[1050], n, x;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> x;
	x--;
	for (int i = 0, j = x + 1; i <= x, j < n; i++, j++)
	{
		b[i] = a[j];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 1; j < x - i; j++)
		{
			if (a[j] <= a[j - 1])
			{
				swap(a[j], a[j - 1]);
			}
		}
	}
	for (int i = 0; i < n - (x + 1); i++)
	{
		for (int j = 1; j < (n - (x + 1)) - i; j++)
		{
			if (b[j] >= b[j - 1])
			{
				swap(b[j], b[j - 1]);
			}
		}
	}
	for (int i = 0, j = x + 1; i <= x, j < n; i++, j++)
	{
		a[j] = b[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
