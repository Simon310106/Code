#include <bits/stdc++.h>
using namespace std;

long long ans[100500], n, a, b = 1, c;
int main()
{
	cin >> n;
	ans[0] = 1;
	ans[1] = 1;
	for (int i = 2; i < n; i++)
	{
		ans[i] = ans[i - 1] + ans[i - 2];
	}
	cout << ans[n - 1];
	return 0;
}
