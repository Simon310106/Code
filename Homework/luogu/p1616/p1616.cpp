#include <bits/stdc++.h>
#define int long long
using namespace std;

int t, m;
int v[100005], w[100005], f[10000005];

signed main(){
    cin >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = w[i]; j <= t; j++) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[t] << endl;
    return 0;
}
