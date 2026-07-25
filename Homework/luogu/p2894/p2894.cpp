#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int s[4*N], suf[4*N], pre[4*N], tag[4*N];

void up(int i, int l, int r) {
    int mid = (l + r) >> 1;
    int left = i << 1;
    int right = i << 1 | 1;
    pre[i] = pre[left];
    suf[i] = suf[right];
    if (pre[left] == mid - l + 1) {
        pre[i] += pre[right];
    }
    if (suf[right] == r - mid) {
        suf[i] += suf[left];
    }
    s[i] = max({s[left], s[right], suf[left] + pre[right]});
}

void down(int i, int l, int r) {
    if (tag[i] == -1) return;
    int mid = (l + r) >> 1;
    int left = i << 1;
    int right = i << 1 | 1;
    s[left] = suf[left] = pre[left] = (tag[i] == 0 ? mid - l + 1 : 0);
    s[right] = suf[right] = pre[right] = (tag[i] == 0 ? r - mid : 0);
    tag[left] = tag[right] = tag[i];
    tag[i] = -1;
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

void update(int i, int l, int r, int ul, int ur, int v) {
    if (ul > r || ur < l) return;
    if (ul <= l && ur >= r) {
        s[i] = pre[i] = suf[i] = (v == 0 ? r - l + 1 : 0);
        tag[i] = v;
        return;
    }
    down(i, l, r);
    int mid = (l + r) >> 1;
    update(i << 1, l, mid, ul, ur, v);
    update(i << 1 | 1, mid + 1, r, ul, ur, v);
    up(i, l, r);
}

int query(int i, int l, int r, int x) {
    if (l == r) return l;
    down(i, l, r);
    int mid = (l + r) >> 1;
    int left = i << 1;
    int right = i << 1 | 1;
    if (s[left] >= x) return query(i << 1, l, mid, x);
    else if (suf[left] + pre[right] >= x) {
        return mid - suf[left] + 1;
    }
    else return query(i << 1 | 1, mid + 1, r, x);
}

int main(){
    int n, m;
    cin >> n >> m;
    memset(tag, -1, sizeof tag);
    build(1, 1, n);
    while(m--) {
        int opr;
        cin >> opr;
        if (opr == 1) {
            int x;
            cin >> x;
            if (s[1] < x) cout << 0 << endl;
            else {
                int pos = query(1, 1, n, x);
                cout << pos << endl;
                update(1, 1, n, pos, pos + x - 1, 1);
            }
        }
        else {
            int x, y;
            cin >> x >> y;
            update(1, 1, n, x, x + y - 1, 0);
        }
    }
    return 0;
}