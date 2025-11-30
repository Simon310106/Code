#include <bits/stdc++.h>
using namespace std;

int main(){
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '-') {
			cout << s[i];
			continue;
		}
		if (s[i - 1] >= '0' && s[i - 1] <= '9' && (s[i + 1] < '0' || s[i + 1] > '9')) {
			cout << '-';
			continue;
		}
		if (s[i + 1] >= '0' && s[i + 1] <= '9' && (s[i - 1] < '0' || s[i - 1] > '9')) {
			cout << '-';
			continue;
		}
		if (s[i - 1] >= s[i + 1]) {
			cout << '-';
			continue;
		}
		if (s[i + 1] == '-' || s[i - 1] == '-') {
			cout << '-';
			continue;
		}
		if (i == 0) {
			cout << '-';
			continue;
		}
		if (p1 == 3 && i != 0) {
			for(char j = s[i - 1] + 1; j < s[i + 1]; j++) {
				for(int k = 1; k <= p2; k++) {
					cout << '*';
				}
			}
			continue;
		}
		
		if (p3 == 1) {
			if (p1 == 1) {
				for (char j = s[i - 1] + 1; j < s[i + 1]; j++) {
					for (int k = 1; k <= p2; k++) {
						cout << char(j);
					}
				}
			}
			if (p1 == 2) {
				for (char j = s[i - 1] - 31; j < s[i + 1] - 32; j++) {
					for (int k = 1; k <= p2; k++) {
						if ((s[i + 1] >= '0' && s[i + 1] <= '9') || (s[i - 1] >= '0' && s[i - 1] <= '9')) {
							cout << char(j + 30);
						}
						else {
							cout << char(j);
						}
					}
				}
			}
		}
		if (p3 == 2) {
			if (p1 == 1) {
				for (char j = s[i + 1] - 1; j > s[i - 1]; j--) {
					for (int k = 1; k <= p2; k++) {
						cout << char(j);
					}
				}
			}
			if (p1 == 2) {
				for (char j = s[i + 1] - 33; j > s[i - 1] - 32; j--) {
					for (int k = 1; k <= p2; k++) {
						if ((s[i + 1] >= '0' && s[i + 1] <= '9') || (s[i - 1] >= '0' && s[i - 1] <= '9')) {
							cout << char(j + 32);
						}
						else {
							cout << char(j);
						}
					}
				}
			}
		}
	}
	return 0;
}

