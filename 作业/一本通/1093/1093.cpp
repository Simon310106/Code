#include <bits/stdc++.h>
using namespace std;

int main()
{
	double x, n;
	double ans = 0;
	cin >> x >> n;
	
	for (int i = 0; i <= n; i++)
	{
		ans = ans + pow(x, i);
	}
	
	cout << fixed << setprecision(2) << ans;
	return 0;
}
