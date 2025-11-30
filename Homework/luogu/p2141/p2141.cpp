#include <bits/stdc++.h>
using namespace std;

int a[110];
bool p[110];

int main(){
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (k != i && k != j && a[i] + a[j] == a[k] && p[k] == 0) {
                    ans++;
                    p[k] = 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}