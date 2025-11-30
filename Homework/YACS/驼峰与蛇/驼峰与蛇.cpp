#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, ans = "";
	cin >> s;
	for (int i = 0; i < s.length(); ) {
		string t = "";
		if (s[i] >= 'A' && s[i] <= 'Z') {
			if (i != 0) {
				t = '_';
			}
			t += s[i++] + 32;
			while (s[i] >= 'a' && s[i] <= 'z') {
				t += s[i];
				i++;
			}
		}
		ans += t;
	}
	cout << ans;
	return 0;
}

