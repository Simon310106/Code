#include <bits/stdc++.h>
using namespace std;

int ans[150], cnt;
int main()
{
	while(cin >> ans[cnt])
	{
		cnt++;
	}
	for (int i = cnt - 1; i >= 0; i--)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
