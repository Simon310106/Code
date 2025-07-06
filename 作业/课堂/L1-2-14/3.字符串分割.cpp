#include <iostream>
#include <algorithm>
using namespace std;

string s;
int n, cnt;
long long a[2000];

long long stol(int l, int r) {
	long long a = 0;
	while (s[l] == '0') {
		l++;
	}
	for (int i = l; i < r; i++) {
		a = a * 10 + s[i] - '0';
	}
	return a;
}

int main() {
	cin >> s;
	
	int i = 0;
	while (s[i] == '5') {
		i++;
	}
	int l = i, r;
	for (; i < s.length(); i++) {
		if (s[i] == '5') {
			r = i;
			while (s[i] == '5') {
				i++;
			}
			a[cnt++] = stol(l, r);
			l = i;
		}
	}
	if (l < s.length() - 1) {
		a[cnt++] = stol(l, s.length());
	}
	sort(a, a + cnt);
	for (int i = 0; i < cnt; i++) {
		cout << a[i];
		if (i < cnt - 1) {
			cout << " ";
		}
	}
	return 0;
}
