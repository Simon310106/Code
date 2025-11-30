#include <bits/stdc++.h>
using namespace std;

int dir = 1, x, y; 

int main(){
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'R') {
			dir--;
			if (dir == 0) {
				dir = 4;
			}
		} 
		else if (s[i] == 'L') {
			dir++;
			if (dir == 5) {
				dir = 1;
			}
		}
		else if (s[i] == 'F') {
			if (dir == 1) {
				x++;
			}
			else if (dir == 2) {
				y++;
			}
			else if (dir == 3) {
				x--;
			}
			else if (dir == 4) {
				y--;
			}
		}
		else if (s[i] == 'B') {
			if (dir == 1) {
				x--;
			}
			else if (dir == 2) {
				y--;
			}
			else if (dir == 3) {
				x++;
			}
			else if (dir == 4) {
				y++;
			}
		}
	} 
	cout << x << " " << y;
	return 0;
}

