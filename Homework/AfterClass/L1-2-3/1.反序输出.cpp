#include <bits/stdc++.h>
using namespace std;

int ans[105], t = 0;
int main()
{
	while(cin >> ans[t])
	{
		t++;
	}
	for (int i = t - 1; i >= 0; i--)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
