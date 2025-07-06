#include <bits/stdc++.h>
using namespace std;

int ans = 1;

struct node {
    int start, end;
}s[1005];

bool cmp(node a, node b) {
    return a.end < b.end;
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].start >> s[i].end;
    }
    sort(s, s + n, cmp);
    int t = s[1].end;
    for (int i = 2; i <= n; i++) {
        if (s[i].start >= t) {
            ans++;
            t = s[i].end;
        }
    }
    cout << ans;
    return 0;
}