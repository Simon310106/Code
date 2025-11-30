#include <bits/stdc++.h>
using namespace std;

long long a[1000005], n, k;

long long check(long long x) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i] / x;
    }
    return sum >= k;
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long l = 0, r = 100000001, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l;

    return 0;
}