#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> q;

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		switch (a) {
			case 1:
				int x;
				cin >> x;
				q.push(x);
				break;
			case 2:
				if (!q.empty()) {
					q.pop();
				}
				else {
					cout << "ERR_CANNOT_POP" << endl;
				}
				break;
			case 3:
				if (!q.empty()) {
					cout << q.front() << endl;
				}
				else {
					cout << "ERR_CANNOT_QUERY" << endl;
				}
				break;
			case 4:
				cout << q.size();
				break;
		}
	}
	return 0;
}

