#include <bits/stdc++.h>
using namespace std;

int row[65];
vector<int> fa;

int find(int a) {
    if (fa[a] == a) {
        return a;
    }
    return fa[a] = find(fa[a]);
}

void merge(int a, int b) {
    int x = find(a), y = find(b);
    if (x != y) {
        fa[x] = y;
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> row[i];
    }
    fa.resize(n + 5);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    int cnt = 0, ans = 0;
    while (cnt != 2 * n) {
        int a = row[++cnt] / 2 + 1;
        int b = row[++cnt] / 2 + 1;
        if (a == b || find(a) == find(b)) {
            continue;
        }
        merge(a, b);
    }
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i) {
            ans++;
        }
    }
    cout << n - ans;
    return 0;
}
/*
1 (0, 1)
2 (2, 3)
3 (4, 5)
4 (6, 7)
5 (8, 9)
(n, n + 1)    n / 2 + 1
*/