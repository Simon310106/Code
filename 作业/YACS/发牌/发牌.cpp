#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		q.push(q.front());
		q.pop();
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}

