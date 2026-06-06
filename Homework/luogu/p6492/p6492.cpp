#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int a[N], s[4 * N], pre[4 * N], suf[4 * N];

void up(int i, int l, int r) {
    int mid = (l + r) >> 1;
    int left = i << 1;
    int right = i << 1 | 1;
    s[i] = max(s[left], s[right]);
    pre[i] = pre[left];
    suf[i] = suf[right];
    if (a[mid] != a[mid + 1]) {
        s[i] = max(s[i], suf[left] + pre[right]);
        if (pre[left] == mid - l + 1) {
            pre[i] = pre[left] + pre[right];
        }
        if (suf[right] == r - mid) {
            suf[i] = suf[right] + suf[left];
        }
    }
}

void build(int i, int l, int r) {
    if (l == r) {
        s[i] = pre[i] = suf[i] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    up(i, l, r);
}

void update(int i, int l, int r, int k) {
    if (l == r) {
        a[k] ^= 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (k <= mid) update(i << 1, l, mid, k);
    else update(i << 1 | 1, mid + 1, r, k);
    up(i, l, r);
} 

int main(){
    int n, q;
    cin >> n >> q;
    build(1, 1, n);
    while(q--) {
        int x;
        cin >> x;
        update(1, 1, n, x);
        cout << s[1] << endl;
    }
    return 0;
}