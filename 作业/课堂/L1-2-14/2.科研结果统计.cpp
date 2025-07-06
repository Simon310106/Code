#include <bits/stdc++.h>
using namespace std;

long long a[10000020];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int cnt = 0;
	cout << a[0] << " ";
	for (int i = 0; i < n; i++) {
		if (i != 0 && a[i] != a[i - 1]) {
			cout << cnt << endl;
			cout << a[i] << " ";
			cnt = 1;
		} 
		else {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
