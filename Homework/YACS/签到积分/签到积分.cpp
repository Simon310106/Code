#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int ans = 0, sum = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'Y') {
			sum++;
			if (sum > 5) {
				sum = 5;
			}
			ans += sum;
		}
		else if (s[i] == 'N') {
			sum = 0;
		}
	}
	cout << ans;
	return 0;
}

