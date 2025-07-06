#include <bits/stdc++.h>
using namespace std;

long long y[20050];

int main(){
    long long n, ma = -0x3f3f3f3f, mi = 0x3f3f3f3f, t = 0x3f3f3f3f;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x >> y[i];
        ma = max(ma, y[i]);
        mi = min(mi, y[i]);
    }
    for (int i = mi; i <= ma; i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += abs(i - y[j]);
        }
        t = min(t, sum);
    }
    cout << t;

    return 0;
}