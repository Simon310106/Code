#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return t == s;
} 

int main(){
	string s;
	cin >> s;
	while (check(s) || s.length() == 1) {
		s = s.substr(0, s.length() / 2);
	}
	cout << s.length();
	return 0;
}

