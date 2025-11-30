#include <bits/stdc++.h>
using namespace std;

int main(){
	int h1, h2, m1, m2, s1, s2;
	char c;
	cin >> h1 >> c >> m1 >> c >> s1;
	cin >> h2 >> c >> m2 >> c >> s2;
	int h, m, s;
	s = ((h1 - h2) * 60 + (m1 - m2)) * 60 + (s1 - s2);
	cout << s;
	return 0;
}

