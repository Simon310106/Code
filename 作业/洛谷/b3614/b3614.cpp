#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

signed main(){
	int T;
	cin >> T;
	while (T--) {
		stack <int> s;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			string a;
			cin >> a;
			if (a == "push") {
				int x;
				cin >> x;
				s.push(x);
			}
			if (a == "pop") {
				if (!s.empty()) {
					s.pop();
				}
				else {
					cout << "Empty" << endl;
				}
			}
			if (a == "query") {
				if (!s.empty()) {
					cout << s.top() << endl;
				}
				else {
					cout << "Anguei!" << endl;
				}
			}
			if (a == "size") {
				cout << s.size() << endl;
			}
		}
		
	}
	return 0;
}

