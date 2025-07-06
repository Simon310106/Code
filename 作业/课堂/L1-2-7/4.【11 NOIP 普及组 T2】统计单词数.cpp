#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int main()
{
	
	getline(cin, s1);
	s1 += ' ';
	s1 = ' ' + s1;
	getline(cin, s2);
	s2 += ' ';
	s2 = ' ' + s2;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
		{
			s1[i] += 32;
		}
	}
	for (int i = 0; i < s2.length(); i++)
	{
		if (s2[i] >= 'A' && s2[i] <= 'Z')
		{
			s2[i] += 32;
		}
	}
	bool flag = 0;
	int ans = 0, pos;
	for (int i = 0; i < s2.length() - s1.length(); i++)
	{
		if (s2.substr(i, s1.length()) == s1)
		{
			if (flag == 0)
			{
				pos = i;
				flag = 1;
			}
		ans++;
		}

	}
	if (flag)
	{
		cout << ans << " " << pos;
	}
	else
	{
		cout << -1;
	}
	return 0;
}
