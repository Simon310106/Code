#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x;
	unsigned long long ans = 1;
	cin >> x;
	
	//sbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsb
	while (x != 0)
	{
		ans = ans * 10 + (x & 1);
		x = x >> 1;
	}
	while (ans != 1)
	{
		cout << ans % 10;
		ans /= 10;
	}
	return 0;
}
