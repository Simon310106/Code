#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 10 == 6 && i % 8 == 0)
		{
			cout << "magic ";
		}
		else
		{
			cout << i << " ";
		}
	}
	return 0;
}
