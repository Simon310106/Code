#include <bits/stdc++.h>
using namespace std;

void complete(int n) {
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			ans += i;
		}
	}
	if (ans == n) {
		cout << ans << endl;
		return;
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		complete(i);
	}
	
	return 0;
}
