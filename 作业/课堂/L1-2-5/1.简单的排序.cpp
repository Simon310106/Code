#include <bits/stdc++.h>
using namespace std;

int a[1020], n, mi;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		mi = i;
		for (int j = i; j < n; j++)
		{
			if (a[mi] > a[j])
			{
				mi = j;
			}
		}
		swap(a[mi], a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
