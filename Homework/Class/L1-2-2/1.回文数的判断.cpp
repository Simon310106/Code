#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, n = 0, t = 0;
	cin >> a;
	n = a;
	
	while (n != 0)
	{
		t = n % 10 + t * 10;
		n /= 10;
	}
	if (t == a)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
