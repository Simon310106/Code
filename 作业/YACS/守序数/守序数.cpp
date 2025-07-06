#include <bits/stdc++.h>
#define int long long 
using namespace std;

queue <int> q;

signed main(){
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		if (i == n) {
			cout << x;
			return 0;
		}
		q.pop();
		if (x % 10 == 0) {
			q.push(x * 10);
			q.push(x * 10 + 1);
		}
		else if (x % 10 == 9) {
			q.push(x * 10 + 8);
			q.push(x * 10 + 9);
		}
		else {
			for (int j = -1; j <= 1; j++) {
				q.push(x * 10 + x % 10 + j);
			}
		}
	} 
	return 0;
}

