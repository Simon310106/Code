#include <bits/stdc++.h>
using namespace std;

long long n, a[100005], f[100005], vis[30];
string s;

int main(){
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0ll, sizeof(vis));
        f[i] = f[i - 1] + a[1];
        vis[s[i - 1] - 'a'] = 1;
        for (int j = i - 1; j >= 1; j--) {
            int now = s[j - 1] - 'a';
            if (vis[now]) {
                break;
            }
            vis[now] = 1;
            f[i] = max(f[i], f[j - 1] + a[i - j + 1]);
        }
    }
    cout << f[n];
    return 0;
}