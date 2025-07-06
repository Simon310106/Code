#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long a[10090], b[10090], c[10090];

string sub(string a1, string b1) {
    int lena = a1.length();
    int lenb = b1.length();
	if (lena < lenb || (lena == lenb && a1 < b1)) {
		cout << "-";
		swap(a1, b1);
		swap(lena, lenb);
	}
    for (int i = 0; i < lena; i++) {
        a[lena - i] = a1[i] - '0';
    }
    for (int i = 0; i < lenb; i++) {
        b[lenb - i] = b1[i] - '0';
    }
    int lenc = 1;
    int x = 0;
    for (int i = 1; i <= lena; i++) {
		if (a[i] < b[i]) {
			a[i + 1]--;
			a[i] += 10;
		}
		c[i] = a[i] - b[i];
	}
	lenc = lena;
    while (c[lenc] == 0 && lenc > 1) {
        lenc--;
    }
    string ans = "";
    for (int i = lenc; i >= 1; i--) {
        ans += char(c[i] + '0');
    }
    return ans;
}

int main(){
	string a1, b1;
	cin >> a1 >> b1;
	cout << sub(a1, b1);
	return 0;
}