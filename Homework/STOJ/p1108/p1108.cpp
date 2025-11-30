#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int i, j;
	for (i = 0; i < s.length(); i++) {
		if (s[i] != '*') {
			break;
		}
		cout << s[i];
	}
	for (j = s.length() - 1; j >= 0; j--) {
		if (s[j] != '*'){
			break;
		}
	}
	for ( ; i <= j; i++) {
		if (s[i] != '*') {
			cout << s[i];
		}
	}
	for (j = j + 1 ; j < s.length(); j++) {
		cout << s[j];
	}
	return 0;
}

