#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, ans;

struct node {
    int w, hei;
    bool operator < (const node &b) const {
        return (b.w == w ? hei > b.hei : w > b.w);
    }
};

priority_queue<node> q;

signed main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int w;
        cin >> w;
        q.push({w, 1});
    }
    while ((q.size() - 1) % (k - 1) != 0) {
        q.push({0, 1});
    }
    while (q.size() >= k) {
        int sum = 0, h = -1;
        for (int i = 1; i <= k; i++) {
            node t = q.top();
            sum += t.w;
            h = max(h, t.hei);
            q.pop();
        }
        ans += sum;
        q.push({sum, h + 1});
    }
    cout << ans << endl << q.top().hei - 1 << endl;
    return 0;
}