#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, ans = "";
	cin >> s;
	for (int i = 0; i < s.length(); ) {
		string t = s.substr(i, 2);
		if (t == "00") {
			ans += "<";
			i += 2; 
		}
		else if (t == "11") {
			ans += ">";
			i += 2;
		}
		else {
			t = s.substr(i, 3);
			if (t == "010") {
				ans += "[";
			}
			else if (t == "101") {
				ans += "]";
			}
			else if (t == "011") {
				ans += "+";
			}
			else if (t == "100") {
				ans += "-";
			}
			i += 3;
		}
	}
	cout << ans;
	return 0;
}

