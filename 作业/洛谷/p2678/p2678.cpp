#include <bits/stdc++.h>
using namespace std;

int k, n, m;
int pos[50005];

bool check(int mid) {
    int ans = 0, st = 0;
    for (int i = 1; i <= n; i++) {
        if (pos[i] - st < mid) {
            ans++;
        } else {
            st = pos[i];
        }
    }
    return ans <= m;
}

int main(){
    cin >> k >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
    }
    sort(pos + 1, pos + n + 1);
    int l = 1, r = k, mid = 0;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    if (!check(l)) {
        l -= 1;
    }
    cout << l << endl;
    return 0;
}