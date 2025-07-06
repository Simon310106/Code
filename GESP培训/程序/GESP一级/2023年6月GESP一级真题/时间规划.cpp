#include <bits/stdc++.h>

using namespace std;

int main()
{
	int h1, h2, m1, m2, ans = 0;
	cin >> h1 >> m1 >> h2 >> m2;
	ans = 60 * (h2 - h1);
	if (m2 > m1) ans += m2 - m1;
	else if (m2 < m1) ans -= m1 - m2;
	cout << ans << endl;
	return 0;
}
