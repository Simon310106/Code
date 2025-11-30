#include <bits/stdc++.h>
using namespace std;

int s[500005], ma, t[500005], maxn, id;

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		s[i] = a;
		t[i] = b;
		if (maxn < s[i] - t[i]) {
			maxn = s[i] - t[i];
			id = i;
		}
	}
	ma = s[id];
	for (int i = 1; i <= n; i++) {
		if (i != id) {
			ma += t[i];
		}
	}
	cout << ma;
	return 0;
}

