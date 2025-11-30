#include <bits/stdc++.h>
using namespace std;

bool palindromic(string s) {
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] != s[n - i - 1]){
			return false;
		}
	}
	return true;
}

int main(){
	string s;
	cin >> s;
	while(s.size() % 2 == 0 && palindromic(s)) {
		s = s.substr(0, s.size() / 2);
	}
	cout << s.size();
	return 0;
}
