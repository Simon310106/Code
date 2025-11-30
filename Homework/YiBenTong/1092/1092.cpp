#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	double e = 1.0;
	long long fac = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		fac *= i;
		e = e + 1.0 / fac;
	}
	cout << fixed << setprecision(10) << e;
	return 0;
}
