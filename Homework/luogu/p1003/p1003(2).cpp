#include <bits/stdc++.h>
using namespace std;

struct carpet {
    int a, b, c, d;
}c[10005];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i].a >> c[i].b >> c[i].c >> c[i].d;
    }
    int x, y;
    cin >> x >> y;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (x >= c[i].a && y >= c[i].b && x <= c[i].a + c[i].c && y <= c[i].b + c[i].d) {
            ans = i + 1;
        }
    }
    cout << ans;
    return 0;
}