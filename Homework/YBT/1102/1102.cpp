#include <bits/stdc++.h>
using namespace std;

int ans[105], n, a, answer = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ans[i];
	}
	cin >> a;
	for (int i = 0; i < n; i++)
	{
		if (a == ans[i])
		{
			answer++;
		}
	}
	cout << answer;
	return 0;
}
