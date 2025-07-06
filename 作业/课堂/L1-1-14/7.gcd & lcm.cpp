#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	int gcd = 0, lcm = 0;
	cin >> a >> b;
	
	while (a != 0 && b != 0)
	{
		int c = 
		if (a > b)
		{
			a %= b;
		}
		else
		{
			b %= a; 
		}
	}
	gcd = a + b;
	lcm = a * b / double(gcd);
	cout << "gcd = " << gcd << endl;
	cout << "lcm = " << lcm << endl;
	return 0;
}
