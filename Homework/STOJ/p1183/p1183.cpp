#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, a, b;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			a += s[i];
		}
		else {
			b += s[i];
		}
	} 
	cout << a << b;
	return 0;
}

