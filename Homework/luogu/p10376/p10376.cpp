#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, a, b, c;
ll f[200005];
const int mod = 1e9 + 7;

ll dfs(ll x) {
    if (x <= c) {
        return 1;
    }
    if (f[x] != 0) {
        return f[x];
    }
    f[x] = (dfs(x - a) % mod + dfs(x - b) % mod) % mod;
    return f[x];
}

int main(){
    cin >> n >> a >> b >> c;
    cout << dfs(n) << endl;
    return 0;
}