#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
struct node {
    int d, p;
    const bool operator<(const node &b) {
        if (d == b.d) {
            return p > b.p;
        }
        return d < b.d;
    }
}t[N];

int n;

signed main(){
    // freopen("p2949_3.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i].d >> t[i].p;
    }
    sort(t + 1, t + 1 + n);
    int sum = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
        sum++;
        q.push(t[i].p);
        if (sum <= t[i].d) ans += t[i].p;
        if (sum > t[i].d) {
            ans -= q.top();
            q.pop();
            sum--;
        }
    }
    cout << ans;
    return 0;
}