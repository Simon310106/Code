#include <bits/stdc++.h>
using namespace std;

int a[100050], b[100050], n, cnt;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i])
		{
			cnt++;
		}
	}
	if (cnt == n)
	{
		cout << "Equal";
		return 0;
	}
	cout << "Not equal";
	return 0;
}
