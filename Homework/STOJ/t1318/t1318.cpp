#include <bits/stdc++.h>
using namespace std;

int n, len = 0, a[10005], s = 1;

void dfs(int step) {
	if (step == n && a[0] != n - 1) {
		cout << n - 1 << "=";
		for (int i = 0; i < len; i++) {
			cout << a[i];
			if (i < len - 1) {
				cout << '+';
			}
		}
		cout << endl;
		return;
	} 
	for (int i = s; i <= n; i++) {
		if (step + i > n) {
			continue;
		}
		a[len++] = i;
		s = i;
		dfs(step + i);
		len--;
	}
}

int main(){
	cin >> n;
	if (n == 1) {
		cout << "1=1";
	}
	else {
		n++;
		dfs(1);
	}
	return 0;
}

