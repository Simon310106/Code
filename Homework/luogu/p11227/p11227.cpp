#include <bits/stdc++.h>
using namespace std;

bool poker[60];

int main(){
	int n; 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int a, b;
		if (s[0] == 'D') a = 1;
		else if (s[0] == 'C') a = 2;
		else if (s[0] == 'H') a = 3;
		else if (s[0] == 'S') a = 4;
		if (s[1] >= '0' && s[1] <= '9') b = s[1] - '0';
		else if (s[1] == 'A') b = 1;
		else if (s[1] == 'T') b = 10;
		else if (s[1] == 'J') b = 11;
		else if (s[1] == 'Q') b = 12;
		else if (s[1] == 'K') b = 13;
		poker[(a - 1) * 13 + b] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= 52; i++) {
		if (!poker[i]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

