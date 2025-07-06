#include <bits/stdc++.h>
using namespace std;

char c[225], ans[225];
int n, cnt, temp;
int main()
{
	cin.getline(c, 225);
	n = strlen(c);
	for (int i = 0; i < n; i++)
	{
		if (c[i] != ' ')
		{
			cout << c[i];
			cnt = 0;
		}
		else
		{
			cnt++;
			if (cnt == 1)
			{
				cout << c[i];
			}
		}
	}
	return 0;
}
