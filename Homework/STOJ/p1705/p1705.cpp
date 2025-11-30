#include <bits/stdc++.h>
using namespace std;

priority_queue <int, vector<int>, greater<int> > q; 
int ans;

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		q.push(t);
	}
	int x = 0, y = 0;
	while (q.size() > 1) {
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		ans += x + y;
		q.push(x + y);
	}
	cout << ans;
	return 0;
}

