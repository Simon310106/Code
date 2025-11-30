#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string s, mi;
	cin >> s;
	mi = s;
	for (int i = 1; i < n; i++) {
		cin >> s;
		mi = min(s, mi);
	}
	cout << mi;
	return 0;
}

