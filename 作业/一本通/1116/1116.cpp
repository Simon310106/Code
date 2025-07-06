#include <bits/stdc++.h>
using namespace std;

int a[100500], n, ans, t = 1;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == a[i + 1])
		{
			t++;
		}
		else if(t > ans)
		{
			ans = t;
			t = 1;
		}
		else
		{
			t = 1;
		}
	}
	cout << ans;
	return 0;
}
