#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull a[10005], ans, n;

ull Hash(string s) {
    ull k = 0;
    for (int i = 0, base = 131; s[i]; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            k = k * base + (s[i] - '0') + 1;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            k = k * base + (s[i] - 'A') + 11;
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            k = k * base + (s[i] - 'a') + 37;
        }
    }
    return k;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        a[i] = Hash(str);
    }
    sort(a, a + n);
    int ans;
    ans = unique(a, a + n) - a;
    cout << ans;
    return 0;
}