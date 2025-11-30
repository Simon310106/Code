#include <bits/stdc++.h>
using namespace std;

int main()
{
	int r, m, y;
	double t;
	cin >> r >> m >> y;
	t = m;
	
	for (int i = 1; i <= y; i++)
	{
		t = t * (1 + r / 100.0);
	}
	cout << int(t);
	return 0;
}
