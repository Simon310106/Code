#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];

int main(){
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] == c + a[j]) {
                ans++;
            }
            if (a[i] - a[j] < c) {
                break;
            }
        }
    }
    cout << ans;
    return 0;
}