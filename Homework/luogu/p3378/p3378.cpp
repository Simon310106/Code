#include <bits/stdc++.h>
using namespace std;

priority_queue <int, vector<int>, greater<int> > q;

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int t;
			cin >> t;
			q.push(t);
		}
		else if (op == 2) {
			cout << q.top() << endl;
		}
		else if (op == 3) {
			q.pop();
		}
	}
	return 0;
}

