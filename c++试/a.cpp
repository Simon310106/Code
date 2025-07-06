#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main(){
	int n;
	cin >> n;
	while (n--) {
		char c;
		cin >> c;
		if (c == 'I') {
			int temp;
			cin >> temp;
			s.insert(temp);
		}
		if (c == 'Q') {
			int temp;
			cin >> temp;
			if (s.find(temp) != s.end()) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}
