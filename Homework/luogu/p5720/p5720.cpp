#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, day = 1;
	cin >> a;
	
	while (a > 1)
	{
		a /= 2;
		day++;
	}
	
	cout << day;
	return 0;
}
