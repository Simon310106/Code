#include <bits/stdc++.h>
using namespace std;

char j[55], s[55];
int ans;

int main()
{
	cin >> j >> s;
	for (int i = 0; i < strlen(s); i++)
	{
		for (int k = 0; k < strlen(j); k++)
		{
			if (j[k] == s[i])
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
