#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		if (a % i == 0)
		{
			cout << i << endl;
		}
	}
	return 0;
}
