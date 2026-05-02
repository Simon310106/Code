#include <bits/stdc++.h>
using namespace std;

const int N = 150005;
struct node {
    int a, b;
    const bool operator<(const node& tmp) {
        return b < tmp.b;
    }
}t[N];
priority_queue<int> q;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i].a >> t[i].b;
    }
    sort(t, t + n);
    long long sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        sum += t[i].a;
        q.push(t[i].a);
        if (sum <= t[i].b) {
            ans++;
        }
        else {
            sum -= q.top();
            q.pop();
        }
    }
    cout << ans;
    return 0;
}