#include <bits/stdc++.h>
using namespace std;

int a[205], ans;

int main(){
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		a[i] = s[i] - '0';
	}
	for (int i = 0; i < s.length(); i++) {
		ans += a[i];
	}
	cout << ans;
	return 0;
}

