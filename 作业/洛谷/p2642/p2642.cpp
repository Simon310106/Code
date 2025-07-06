#include <bits/stdc++.h>
#define int long long
using namespace std;

int x[1000010], f[1000010], l[1000010];

signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x[i];
    }
    f[1] = x[1];
    for (int i = 2; i <= n; i++){
        f[i] = max(f[i - 1] + x[i], x[i]);
    }
    for (int i = 2; i <= n; i++){
        f[i] = max(f[i], f[i - 1]);
    }
    l[n] = x[n];
    for (int i = n - 1; i >= 1; i--){
        l[i] = max(l[i + 1] + x[i], x[i]);
    }
    for (int i = n - 1; i >= 1; i--){
        l[i] = max(l[i], l[i + 1]);
    }
    int ans = f[1] + l[3];
    for (int i = 3; i < n; i++){
        ans = max(ans, f[i - 1] + l[i + 1]);
    }
    cout << ans << endl;
    return 0;
}