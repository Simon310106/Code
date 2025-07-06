#include <bits/stdc++.h>
using namespace std;

int a[20], t, n;

void dfs(int x) {
	if (x == n + 1) {
		for (int i = 1; i <= t; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		return;
	}
	a[++t] = x;
	dfs(x + 1);
	--t;
	dfs(x + 1);
}

int main(){
	cin >> n;
	dfs(1);
	return 0;
}

