#include <bits/stdc++.h>
using namespace std;

int f[305], cnt[305];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> f[i];
    }
    f[0] = -1;
    int q;
    cin >> q;
    while (q--) {
        memset(cnt, 0, sizeof(cnt));
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            while (x != -1) {
                cnt[x]++;
                x = f[x];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (cnt[i] == m) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}