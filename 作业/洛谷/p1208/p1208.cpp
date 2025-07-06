#include <bits/stdc++.h>
using namespace std;

struct node{
    int prize, total;
}a[5010];

bool cmp(node a, node b) {
    if (a.prize != b.prize) {
        return a.prize < b.prize;
    }
    else {
        return a.total > b.total;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i].prize >> a[i].total;
    }
    sort(a, a + m, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].total > n) {
            ans += n * a[i].prize;
            n = 0;
        }
        else {
            ans += a[i].total * a[i].prize;
            n -= a[i].total;
        }
    }
    cout << ans;
    return 0;
}