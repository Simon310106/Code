#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, ans = 0, temp = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a;
		if (b + 1 == a)
		{
			temp++;
		}
		else
		{
			temp = 1;
		}
		b = a;
		ans = max(temp, ans);
	}
	cout << ans;
	return 0;
}
