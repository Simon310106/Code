#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, z, q, money;
	cin >> x >> y >> z >> q;
	
	money = x * 2 + y * 5 + z * 3;
	if (money <= q)
	{
		cout << "Yes\n";
		cout << q - money;
	}
	else
	{
		cout << "No\n";
		cout << money - q;
	}
	return 0;
}
