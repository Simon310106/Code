#include <bits/stdc++.h>
using namespace std;

int n, a[10005], ans;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}