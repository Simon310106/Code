#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, ans = 0, flag = 0;
	cin >> n;
	
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << n / i;
			return 0;
		}
	}
	return 0;
}
