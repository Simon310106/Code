#include <bits/stdc++.h>
using namespace std;

int a[27];

int main(){
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		a[s[i] - 'a']++;
	}
	int ma = 0;
	char ans;
	for (int i = 0; i <= 26; i++) {
		if (a[i] >= ma) {
			ma = a[i];
			ans = char(i + 'a');
		}
	}
	cout << ans;
	return 0;
}

