#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		ans = max(ans, s);
	}
	cout << ans;
	return 0;
}
