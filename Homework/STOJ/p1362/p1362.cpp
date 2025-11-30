#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = (s[i] - 5 >= 'A' ? s[i] - 5 : s[i] - 5 + 26);
		}
	}
	cout << s;
	
	return 0;
}

