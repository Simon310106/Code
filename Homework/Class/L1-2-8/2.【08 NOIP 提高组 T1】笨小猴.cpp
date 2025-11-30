#include <bits/stdc++.h>
using namespace std;

bool prime(int a)
{
	if (a == 0)
	{
		return 0;
	}
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
string s;
int a[30], maxn = 0, minn = 0x3f3f3f3f;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		a[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		maxn = max(maxn, a[i]);
		if (a[i] != 0)
		{
			minn = min(minn, a[i]);
		}
	}
	if (prime(maxn - minn))
	{
		cout << "Lucky Word" << endl << maxn - minn;
	}
	else
	{
		cout << "No Answer" << endl << 0;
	}
	return 0;
}
