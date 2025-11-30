#include <bits/stdc++.h>
using namespace std;

int pri[100000050], cnt;
bool vis[100000050];

void prime(int n) {
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			pri[++cnt] = i;
		}
		for (int j = 1; j <= cnt && i * pri[j] <= n; j++) {
			vis[pri[j] * i] = 1;
			if (i % pri[j] == 0) {
				break;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int n, q;
	cin >> n >> q;
	prime(n);
	while (q--) {
		int t;
		cin >> t;
		cout << pri[t] << "\n";
	}
	return 0;
}
