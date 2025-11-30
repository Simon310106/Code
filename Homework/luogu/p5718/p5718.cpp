#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, i = 1, mi = 2000000;
	cin >> n;
	
	while (i <= n)
	{
		int a;
		cin >> a;
		mi = min(a,mi);
		i++;
	}
	cout << mi;
	return 0;
}
