#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	string ans;
	int temp = 0;
	while (temp < s.length() && s[temp] == ' ') {
		temp++;
	}
	ans += (s[temp] >= 'A' && s[temp] <= 'Z' ? s[temp] : s[temp] + ('A' - 'a'));
	for (int i = temp; i < s.length(); i++) {
		if (s[i] == ' ') {
			while (i < s.length() && s[i] == ' ') {
				i++;
			} 
			ans += (s[i] >= 'A' && s[i] <= 'Z' ? s[i] : s[i] + ('A' - 'a'));
		}
	}
	cout << ans; 
	return 0;
}

