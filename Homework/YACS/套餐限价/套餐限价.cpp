#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], b[N];

int main(){
	int n, m, l;
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] + b[j] < l) {
				sum += a[i] + b[j];
			}
			else {
				sum += (m - j + 1) * l;
				break;
			}
		}
	}
	cout << sum;
	return 0;
}

