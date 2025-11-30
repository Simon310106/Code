#include <bits/stdc++.h>
using namespace std;

int n, r, a[100];

void dfs(int step) {
	if (step == r + 1) {
		for (int i = 1; i <= r; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		return; 
	}
	for (int i = a[step - 1] + 1; i <= n; i++) {
		a[step] = i;
		dfs(step + 1);
	}
}

int main(){
	cin >> n >> r;
	dfs(1);
	return 0;
}

