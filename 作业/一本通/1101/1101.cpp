#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, x ,y , ans = 0;
	double temp;
	cin >> a >> b >> c;
	
	for (x = 0; x <= c / a; x++)
	{
		temp = (c - a * x) * 1.0 / b;
		if (temp == int(temp) && temp >= 0)
		{
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}
