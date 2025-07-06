#include <bits/stdc++.h>
using namespace std;

int x, r, s;
int a[10005]; 

void dfs(int num, int step) {
	if (num < r) {
		a[step] = num;
		s = step;
		return;
	}
	int i = num % r;
	a[step] = i;
	int j = num / r;
	dfs(j, step + 1);
}

int main(){
	cin >> x >> r;
	dfs(x, 1);
	for (int i = s; i >= 1; i--) {
		if (a[i] <= 9) {
			cout << char(a[i] + 48);
		}
		else {
			cout << char(a[i] + 55);
		}
	}
	
	return 0;
}
