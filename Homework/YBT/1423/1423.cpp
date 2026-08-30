#include <bits/stdc++.h>
using namespace std;

int n, m, f[30010], sum;

struct node{
    int l, r, tree;
}a[5010];

bool cmp(node x, node y) {
    return x.r < y.r;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i].l >> a[i].r >> a[i].tree;
    }
    sort (a, a + m, cmp);
    for (int i = 0; i < m; i++) {
        int h = 0, x = 0;
        for (int j = a[i].l; j <= a[i].r; j++) {
            if (f[j]) {
                x++;
            }
        }
        if (x >= a[i].tree) {
            continue;
        }
        else {
            h += x;
        }
        for (int j = a[i].r; j >= a[i].l; j--) {
            if (h == a[i].tree) {
                break;
            }
            if (f[j]) {
                continue;
            }
            f[j]++, sum++, h++;
        }
    }
    cout << sum;
    return 0;
}