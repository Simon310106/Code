#include <bits/stdc++.h>
using namespace std;

int n, a[1050], ma = 0, ans;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		ma = max(a[i - 1], ma);
		if (a[i - 1] >= ma)
		{
			ans = i;
		}
	}
	cout << ans;
	return 0;
}
