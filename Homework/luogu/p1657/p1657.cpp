#include <bits/stdc++.h>
using namespace std;

int x;
int proj = 0;
int a[25][3];
bool used[25];

void dfs(int k) {
	if (k == x + 1) {
		proj++;
		return;
	}
	for (int i = 1; i <= 2; i++) {
		if (!used[a[k][i]]) {
			used[a[k][i]] = 1;
			dfs(k + 1);
			used[a[k][i]] = 0;
		}
	}
}

int main(){
	cin >> x;
	for (int i = 1; i <= x; i++) {
		cin >> a[i][1] >> a[i][2];
	}
	dfs(1);
	cout << proj;
	return 0;
}
