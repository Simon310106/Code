#include <bits/stdc++.h>
using namespace std;

int a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main(){
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum >= m) {
			cout << i + 1;
			return 0;
		}
	}
	cout << "NO";
	
	return 0;
}

