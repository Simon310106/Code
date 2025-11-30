#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	int ans = 1;
	int i = 0;
	while (i < s.length() && s[i] == ' ') {
		i++;
	} 
	for ( ; i < s.length(); i++) {
		if (s[i] == ' ') {
			ans++;
			while (i < s.length() && s[i] == ' ') {
				i++;
			}
		}
	}
	cout << ans;
	return 0;
}

