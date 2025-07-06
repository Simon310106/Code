#include <bits/stdc++.h>
using namespace std;

int a[1000050], n, b;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> b;
	for (int j = 0; j < n; j++)
	{
		if (a[j] == b)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No"; 
	return 0;
}
