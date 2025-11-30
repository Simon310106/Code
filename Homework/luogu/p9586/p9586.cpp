#include <bits/stdc++.h>
using namespace std;

int t, c1, c2, c3, d1, d2, d3;

int main(){
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> c1 >> c2 >> c3 >> d1 >> d2 >> d3;
		if (c1 > d2 || c3 > d1) {
			cout << "C" << endl;
		}
		else if (d3 > c1 || d1 - c3 > c2) {
			cout << "D" << endl;
		}
		else {
			cout << "E" << endl;
		}
	}
	
	return 0;
}

