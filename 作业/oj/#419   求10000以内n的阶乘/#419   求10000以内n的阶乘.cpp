#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100005;

void strtointarr(string s, int a[]) {
    a[0] = s.size();
    for (int i = 1; i <= a[0]; i++) {
        a[i] = s[a[0] - i] - '0';
    }
}

string mul(string A, int b) {
    int a[N] = {};
    string res = "";
    if (b == 0) {
        return "0";
    }
    strtointarr(A, a);
    int x = 0;
    for (int i = 1; i <= a[0]; i++) {
        int t = b * a[i] + x;
        x = t / 10;
        t %= 10;
        res += char(t + '0');
    }
    while (x) {
        res += char(x % 10 + '0');
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
	int n;
    cin >> n;
    int b = 2;
    string res = "1";
    for (int i = 1; i <= n; i++) {
        res = mul(res, i);
    }
    cout << res << endl;
	return 0;
}