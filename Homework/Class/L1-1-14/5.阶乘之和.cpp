#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, fac = 1, ans = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		fac *= i;
		ans += fac;
	}
	cout << ans;
	return 0;
}
