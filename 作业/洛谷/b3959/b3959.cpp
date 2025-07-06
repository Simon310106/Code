#include <bits/stdc++.h>
using namespace std;

int a[1000050];

int main(){
    int n, ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i] < ans) {
            continue;
        }
        else {
            ans++;
        }
    }
    cout << ans - 1;
    return 0;
}