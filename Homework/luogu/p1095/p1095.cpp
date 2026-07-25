#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int m, s, t, cnt;

int main(){
	cin >> m >> s >> t;
	for (int i = 1; i <= t; i++) {
		int k = min(i, (4 * i + m) / 14);
		int dist = k * 60 + (i - k) * 17;
		if (dist >= s) {
			cout << "Yes\n" << i << endl;
			return 0;
		}
	}
	int k = min(t, (4 * t + m) / 14);
	cout << "No\n" << k * 60 + (t - k) * 17 << endl;
	return 0;
}

