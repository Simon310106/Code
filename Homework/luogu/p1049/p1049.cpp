#include <bits/stdc++.h>
using namespace std;

int val[50], dp[20005];

int main(){
    int v, n;
    cin >> v >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= val[i]; j--) {
            dp[j] = max(dp[j], dp[j - val[i]] + val[i]);
        }
    }
    cout << v - dp[v] << endl;
    return 0;
}