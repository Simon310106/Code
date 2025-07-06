#include <bits/stdc++.h>
using namespace std;

bool a[100005];
int p[100005], cnt;

void prime(int n){
	memset(a, 1, sizeof(a));
	for (int i = 2; i <= n; i++) {
		if (a[i] == 1) {
			p[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * p[j] <= n; j++) {
			a[i * p[j]] = 0;
		}
	}
	return;
}

int main(){
	int n, b;
	cin >> n;
	prime(100005);
	a[0] = 0;
	a[1] = 0;
	for (int i = 0; i < n; i++) {
		cin >> b;
		if (a[b]) {
			cout << b << " ";
		}
	}
	
	return 0;
}
