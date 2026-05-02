#include <bits/stdc++.h>
#define int long long
using namespace std;

priority_queue<int> q;
int a[100005], b[100005];
int ans[100005];

signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        q.push(a[1] + b[i]);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] + b[j] >= q.top()) {
                break;
            } 
            if (a[i] + b[j] < q.top()) {
                q.pop();
                q.push(a[i] + b[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = q.top();
        q.pop();
    }
    for (int i = n; i >= 1; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}