#include <bits/stdc++.h>
using namespace std;

int a[10005], lds[10005], lis[10005];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) {
        lds[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] > a[i]) lds[i] = max(lds[i], lds[j] + 1);
        }
    }
    
    for (int i = n; i >= 1; i--) {
        lis[i] = 1;
        for (int j = n; j > i; j--) {
            if (a[j] > a[i]) lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, lds[i] + lis[i] - 1);
    }
    cout << ans << endl;
    return 0;
}