#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e4 + 10;
int a[N], num;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
            long long cnt = 0;
        for (ll j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                cnt++;
                while (a[i] % j == 0) {
                    a[i] /= j;
                }
            }
        }
        if (a[i] > 1) {
            cnt++;
        }
        cout << (cnt == 2) << endl;
    }
    return 0;
}