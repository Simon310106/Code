#include <bits/stdc++.h>
#define int long long
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int ans;

signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    while (q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a + b;
        q.push(a + b);
    }
    cout << ans << endl;
    return 0;
}