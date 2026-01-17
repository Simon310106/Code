#include <bits/stdc++.h>
#define int long long
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

signed main(){
    int n, ans = 0;
    cin >> n;
    while (n--) {
        int a;
        scanf("%lld", &a);
        q.push(a);
    }
    while (q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += (a + b);
        q.push(a + b);
    }
    printf("%lld\n", ans);
    return 0;
}