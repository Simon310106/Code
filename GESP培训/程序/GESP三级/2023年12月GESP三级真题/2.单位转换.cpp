#include <bits/stdc++.h>
using namespace std;

int n, x, t;
string s1, s2, s3, s4;

int main(){
	cin >> n;
	while (n--) {
		cin >> x >> s1 >> s2 >> s3 >> s4;
		if (s1 == "km" && s4 == "m") {
			t = x * 1000;
		}
		else if (s1 == "km" && s4 == "mm") {
			t = x * 1000000;
		}
		else if (s1 == "m" && s4 == "mm") {
			t = x * 1000;
		}
		else if (s1 == "kg" && s4 == "g") {
			t = x * 1000;
		}
		else if (s1 == "kg" && s4 == "mg") {
			t = x * 1000000;
		}
		else if (s1 == "g" && s4 == "mg") {
			t = x * 1000;
		}
		cout << x << " " << s1 << " " << s2 << " " << t << " " << s4 << endl;
	}
	
	return 0;
}
