#include <bits/stdc++.h>
using namespace std;

bool a[100000000];
int b[5780000], cnt;

void prime(int n) {
	memset(a, 1, sizeof(a));
	a[0] = a[1] = 0;
	cnt = 0;
	for (int i = 2; i < n; i++) {
		if (a[i] == 1) {
			b[cnt++] = i;
		}
		for (int j = 0; j < cnt && i * b[j] < n; j++) {
			a[i * b[j]] = 0;
			if (i % b[j] == 0) {
				break;
			}
		}
	}
}

int main(){
	int n, m = 1;
	bool f = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		m *= 10;
	}
	prime(m - 1);
	for (int i = m / 10 + 1; i < m; i++) {
		if (a[i]) {
			f = 1;
			int t = i;
			for (int j = 1; j < n; j++) {
				t /= 10;
				if (a[t] == 0) {
					f = 0;
					break;
				}
			}
			if (f) {
				printf("%d\n", i);
			}
		} 
	}
	
	return 0;
}
