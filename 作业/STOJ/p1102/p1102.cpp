#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, a, b;
	cin >> s;
	int i = 0;
	for (i = 0; i < s.length(); i++) {
		if (s[i] != ',')
			a += s[i];
		else 
			break;
	} 
	for (i = i + 1 ; i < s.length(); i++) {
		b += s[i];
	} 
	cout << b << "," << a;
	return 0;
}

