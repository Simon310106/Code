#include <bits/stdc++.h>
using namespace std;

int a[2010], b[2010];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m, ans = 0;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        b[i] = a[x];
        ans = 0;
        for (int j = 1; j <= i; j++) {
            if (b[j] > b[i]) {
                swap(b[i], b[j]);
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}