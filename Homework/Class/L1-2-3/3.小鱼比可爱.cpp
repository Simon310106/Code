#include <bits/stdc++.h>
using namespace std;

int ai[105], ans[105], temp = 0, n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ai[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (i = 0)
		{
			ans[0] = 0;
		}
		else
		{
			for (int j = 0; j < i + 1; j++)
			{
				if (ai[i - 1] < ai[j])
				{
					temp++;
				}
			}
			ans[i - 1] = temp;
		}
		
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
