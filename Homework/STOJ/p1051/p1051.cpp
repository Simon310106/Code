#include <bits/stdc++.h>
using namespace std;

priority_queue <int, vector<int>, greater<int> > q; 

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		q.push(t);
	}
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	return 0;
}

