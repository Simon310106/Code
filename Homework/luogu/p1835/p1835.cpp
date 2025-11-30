#include <bits/stdc++.h>
using namespace std;

const int MAXP = 1e6 + 5;
int pri[MAXP], cnt;
bool vis[MAXP];           


void prime(int n) {
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) pri[cnt++] = i;
        for (int j = 0; j < cnt && i * pri[j] <= n; j++) {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) break;
        }
    }
}

const int MAXL = 1e6 + 5; 
bool isPrime[MAXL];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, r;
    cin >> l >> r;
    int sqrtr = sqrt(r);
    prime(sqrtr);
    for (int i = 0; i <= r - l; ++i) isPrime[i] = true;
    for (int i = 0; i < cnt; i++) {
        int p = pri[i];
        long long start = max(1LL * p * p, 1LL * ((l + p - 1) / p * p));
        for (long long j = start; j <= r; j += p)
            isPrime[j - l] = false;
    }
    if (l == 1) isPrime[0] = false;

    int ans = 0;
    for (int i = 0; i <= r - l; i++)
        if (isPrime[i]) ans++;
    cout << ans << '\n';
    return 0;
}