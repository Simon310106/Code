#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'Y') {
			ans++;
		}
		else if (s[i] == 'N') {
			if (ans > 0) {
				ans--;
			}
		}
	} 
	cout << ans;
	return 0;
}

