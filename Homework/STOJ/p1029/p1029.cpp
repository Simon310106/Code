#include <bits/stdc++.h>
using namespace std;

int main(){
	string t, s;
	cin >> t;
	t.erase(t.length() - 1, 1);
	s = t;
	reverse(t.begin(), t.end());
	if (s == t) {
		cout << "TRUE";
	}
	else {
		cout << "FALSE";
	}
	
	return 0;
}

