#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int ans, a[N];

int main(){
    int n, b;
    cin >> n >> b;
    for (int i = 2; i <= n; i++) {
        if (!a[i]) {
            for (int j = i; j <= n; j += i) {
                a[j] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] <= b) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}