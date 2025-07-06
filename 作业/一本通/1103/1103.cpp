#include <bits/stdc++.h>
using namespace std;

int a[15], h, ans = 0;
int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	cin >> h;
	h += 30;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] <= h)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
