#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); ) {
		string t = s.substr(i, 8);
		int sum = 0;
		for (int j = 0; j < t.length(); j++) {
			sum += (t[j] - '0') * pow(2, t.length() - j - 1);
		}
		if (i != 0) {
			cout << ".";
		}
		cout << sum;
		i += 8;
	} 
	return 0;
}

