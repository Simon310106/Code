#include <bits/stdc++.h>
using namespace std;

int a[1020], n, t, ans, ma, temp[105];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		a[t] = 1;
		temp[i] = t;
		ma = max(ma, temp[i]);
	}
	for (int i = 0; i <= ma; i++)
	{
		if (a[i] == 1)
		{
			ans++;
		}
	}
	cout << ans << endl;
	for (int i = 0; i <= ma; i++)
	{
		if (a[i] == 1)
		{
			cout << i << " ";
		}
	} 
	return 0;
}
