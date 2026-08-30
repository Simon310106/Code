#include <bits/stdc++.h>
using namespace std;

int a[10000000], n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << a[0];
	return 0;
}
