#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		if (i % 10 != 7 && i % 7 != 0 && i / 10 != 7)
		{
			ans += pow (i, 2);
		}
	}
	cout << ans;
	return 0;
}
