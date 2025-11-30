#include <bits/stdc++.h>
using namespace std;

char fun(char c) {
	if (c >= 'a' && c <= 'z') {
		return 'z' - (c - 'a');
	}
	else if (c >= 'A' && c <= 'Z') {
		return 'Z' - (c - 'A');
	}
	else {
		return c;
	}
} 

int main(){
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		cout << fun(s[i]);
	} 
	return 0;
}

