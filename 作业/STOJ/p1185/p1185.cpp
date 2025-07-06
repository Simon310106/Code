#include <bits/stdc++.h>
using namespace std;

int main(){
	string a, b, c, s;
	getline(cin, a);
	getline(cin, b);
	getline(cin, c);
	for (int i = 0; i < a.length(); ) {
		if (i + b.length() <= a.length() && a.substr(i, b.length()) == b) {
			s += c;
			i += b.length();
		}
		else {
			s += a[i];
			i++;
		}
	}
	cout << s;
	return 0;
}

