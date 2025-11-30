#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = n; i >= 0; i--)
	{
		int coe;
		cin >> coe;
		if (coe > 0 && i != n)
		{
			cout << "+";
		}
		if (coe < 0)
		{
			cout << "-";
		}
		if (abs(coe) > 1 || i == 0 && abs(coe) == 1)
		{
			cout << abs(coe);
		}
		if (coe != 0 && i == 1)
		{
			cout << "x";
		}
		if (coe != 0 && i != 1 && i != 0)
		{
			cout << "x^" << i;
		}
	}
	return 0;
}
