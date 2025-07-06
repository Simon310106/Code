#include <bits/stdc++.h>
using namespace std;

struct node {
    int start, end;
}s[1000010];

bool cmp (node a, node b)  {
    return a.end < b.end;
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].start >> s[i].end;
    }
    sort(s + 1, s + 1 + n, cmp);
    int ans = 1;
    int t = s[1].end;
    for (int i = 2; i <= n; i++) {
        if (s[i].start >= t) {
            ans++;
            t = s[i].end;
        }
    }
    cout << ans << endl;
    return 0;
}