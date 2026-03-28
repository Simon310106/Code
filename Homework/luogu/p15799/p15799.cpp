#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int a[100005], b[100005], ans;
unordered_set<int> s;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        s.insert(b[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (s.find(a[i]) != s.end()) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}