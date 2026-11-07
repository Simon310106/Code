#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, m;
int a[N], last[N], f[N], ans[N];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        f[i]++;
        ans[a[i]] += f[i];
        int j = last[a[i]] + 1;
        f[j] += f[i];
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}