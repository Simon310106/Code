#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e+6 + 10;

int a[MAXN];

int find(int l, int r, int x) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (a[l] == x) {
        return l;
    }
    return -1;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        int s = find(0, n - 1, t);
        if (s != -1) {
            cout << s + 1 << " ";
        }
        else {
            cout << -1 << " ";
        }
    }

    return 0;
}