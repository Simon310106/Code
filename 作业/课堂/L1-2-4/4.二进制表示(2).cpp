#include <bits/stdc++.h>
using namespace std;

unsigned long long ans[70], n, cnt;
int main()
{
	cin >> n;
	while(n != 0)
	{
		ans[cnt++] = (n & 1);
		n = n >> 1;
	}
	for (int i = cnt - 1; i >= 0; i--)
	{
		cout << ans[i];
	}
	return 0;
}
