#include <bits/stdc++.h>
using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	if (a == b) {
		cout << 2;
	}
	else {
		if (a.length() != b.length()) {
			cout << 1;
		}
		else {
			for (int i = 0; i < a.length(); i++) {
				if (a[i] >= 'A' && a[i] <= 'Z') {
					a[i] -= ('A' - 'a');
				}
			}
			for (int i = 0; i < b.length(); i++) {
				if (b[i] >= 'A' && b[i] <= 'Z') {
					b[i] -= ('A' - 'a');
				}
			}
			if (a == b) {
				cout << 3;
			}
			else {
				cout << 4;
			}
 		}
	}
	return 0;
}

