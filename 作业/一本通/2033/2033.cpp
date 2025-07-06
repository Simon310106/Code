#include <bits/stdc++.h>
using namespace std;

int main()
{
	unsigned long long n, fac = 1, ans = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		fac *= i;
		ans += fac;
		ans %= 1000000;
		fac %= 1000000;
	}
	cout << ans;
	return 0;
}
