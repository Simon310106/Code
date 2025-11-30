#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a;
	
	cout << a;
	while (a != 0)
	{
		b = a % 10;
		cout << b;
		a /= 10;
	}
	return 0;
}
