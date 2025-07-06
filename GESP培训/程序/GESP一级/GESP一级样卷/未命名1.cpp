#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, m, s;
	char t;
	cin >> h >> m >> s >> t;
	if (t == 'P') {
		h += 12; 
	}
	int ans = h * 60 * 60 + m * 60 + s;
	cout << ans;
	return 0;
}
