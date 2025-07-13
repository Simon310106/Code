#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;

int c, h;
int v[MAXN], dp[MAXN];

int main(){
    cin >> c >> h;
    for (int i = 1; i <= h; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= h; i++) {
        for (int j = c; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        }
        if (dp[c] == c) {
            cout << c;
            return 0;
        }
    }
    cout << dp[c] << endl;
    return 0;
}