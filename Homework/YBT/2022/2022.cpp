#include <bits/stdc++.h>
using namespace std;

int main()
{
	double m, n, s=0, i=0;
	cin >> m;
	
	while (s < m)
	{
		i++;
		s = s + 1.0 / i;
	}
	cout << i;
	return 0;
}
