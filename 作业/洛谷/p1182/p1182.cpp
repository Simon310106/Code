#include <bits/stdc++.h>
using namespace std;

int a[100050], n, m;

bool check(int mid) {
    int sum = 0, ans = 1;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (sum + a[i] >= mid) {
            sum = a[i];
            ans++;
        }
    }
    return !(ans > m);
}

int find(int l, int r) {
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    return l;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    cout << find(0, n + 1) + 1;
    return 0;
}