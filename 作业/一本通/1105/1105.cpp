#include <bits/stdc++.h>
using namespace std;

int num[150], n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		cout << num[i] << ' ';
	}
	return 0;
}
