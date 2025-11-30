#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long k, l, r, ans = 0;
	cin >> k >> l >> r;
	for (long long i = l; i <= r; i++)
	{
		if (i % 10 == k || i % k == 0)
		{
			ans += i;
		}
	}
	cout << ans;
	return 0;
}
