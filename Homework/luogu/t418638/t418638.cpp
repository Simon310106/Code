#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long a[35];
    unsigned long long x;
    int n = 0, ans = 0;
    while (cin >> x) {
        a[n++] = x;
    }
    if (n == 0) return 0;

    unsigned long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    cout << sum * (1ULL << (n - 1)) << endl;
    return 0;
}