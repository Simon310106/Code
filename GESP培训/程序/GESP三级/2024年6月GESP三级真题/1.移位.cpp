#include <bits/stdc++.h>
using namespace std;

int main(){
	string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n;
	cin >> n;
	n %= 26;
	for (int i = 0; i < 26; i++) {
		int j = (n + i) % 26;
		char t = 'A' + j;
		cout << t;
	}
	
	return 0;
}
