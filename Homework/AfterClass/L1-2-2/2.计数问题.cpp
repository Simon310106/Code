#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x, t, a, ans = 0;
	cin >> n >> x;
	
	for (int i = 1; i <= n; i++)
	{
		t = i;
		while (t != 0)
		{
			if (t % 10 == x)
			{
				ans++;
			}
			t /= 10;
		}
	}
	cout << ans;
}
