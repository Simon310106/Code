#include <bits/stdc++.h>
using namespace std;

int n, q, code[1050], num, need, mi = 0x3f3f3f3f, ans, answer[1050], temp; 
const int minn = 0x3f3f3f3f;

int main()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> code[i];
	}
	for (int i = 0; i < q; i++)
	{
		ans = 0;
		mi = 0x3f3f3f3f;
		cin >> num >> need;
		int s = int(pow(10, num));
		for (int j = 0; j < n; j++)
		{
			if (code[j] % s == need && code[j] < mi)
			{
				mi = code[j];
			}
		}
		if (mi != minn)
		{
			cout << mi << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
