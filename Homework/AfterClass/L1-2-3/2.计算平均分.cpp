#include <bits/stdc++.h>
using namespace std;

int ans[105], cnt = 0, t = 0;
int main()
{
	while(cin >> ans[cnt])
	{
		cnt++;
	}
	for (int i = cnt - 1; i >= 0; i--)
	{
		t += ans[i];
	}
	cout << fixed << setprecision(1) << double(t) / cnt;
	return 0;
}
