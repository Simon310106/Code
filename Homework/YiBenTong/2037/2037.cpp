#include <bits/stdc++.h>
using namespace std;

int ans[1025], m, n, cnt, j = -1;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		while (cnt < m)
		{
			j++;
			cnt++;
			if (j >= n)
			{
				j %= n;
			}
			while (ans[j] != 0)
			{
				j++;
				if (j >= n)
				{
					j %= n;
				}
			}
		}
		ans[j] = 1;
		cout << j + 1 << " ";
		cnt = 0;
	}
	
	return 0;
}
