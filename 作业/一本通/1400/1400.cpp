#include <bits/stdc++.h>
using namespace std;

string a, b, c;

string lower(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;
		}
	}
	return s;
}

int main(){
	int ans = 0, first = -1, t = 0;
	cin >> a;
	cin.get();
	getline(cin, b);
	a = lower(a);
	b = lower(b);
	for (int i = 0; i <= b.size(); i++) {
		if (b[i] == ' ' || b[i] == '\0') {
			c = b.substr(t, i - t);
			if (a == c) {
				if (first == -1) {
					first = t;
				}
				ans++;
			}
			t = i + 1;
		}
	}
	if (first == -1) {
		cout << -1;
	}
	else {
		cout << ans << " " << first;
	}
	return 0;
}
