#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,mi = pow (2, 31) - 1, ma = 0;
	cin >> a;
	
	for (int i = 1; i <= a; i++)
	{
		int n;
		cin >> n;
		
		mi = min(mi, n);
		ma = max(ma, n);
	}
	cout << ma - mi;
	return 0;
}
