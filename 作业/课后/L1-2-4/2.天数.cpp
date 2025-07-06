#include <bits/stdc++.h>
using namespace std;

int y, m, d, day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, ans;
int main()
{
	cin >> y >> m >> d;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
	{
		day[1] = 29;
	}
	for (int i = 0; i < m - 1; i++)
	{
		ans += day[i];
	}
	ans += d;
	cout << ans;
	return 0;
}
