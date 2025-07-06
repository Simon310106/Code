#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], c[N], ma = -INT_MAX;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        if (c[i] > 0 || n == 1) {
            ma += c[i];
        }
    }
    cout << ma;
    return 0;
}