#include <bits/stdc++.h>
using namespace std;

int st[100005][20];
int lg2[100005] = {-1};

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> st[i][0];
        lg2[i] = lg2[i / 2] + 1;
    }
    for (int j = 1; j <= lg2[n]; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        int k = r - l + 1;
        cout << max(st[l][lg2[k]], st[r - (1 << lg2[k]) + 1][lg2[k]]) << endl;
    }
    return 0;
}