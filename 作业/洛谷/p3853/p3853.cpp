#include <bits/stdc++.h>
using namespace std;

int l, n, k;
int a[100005];

bool check(int x) {
    int res = 0;
    for (int i = 1; i <= n + 1; i++) {
        int d = a[i] - a[i - 1];
        res += (d - 1) / x;
        if (res > k) return false;
    }
    return true;
}

int main() {
    cin >> l >> n >> k;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = l;

    int left = 1, right = l;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
    return 0;
}
