#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int s[4*N], tag[4*N];

void pushup(int i) {
    s[i] = s[i << 1] + s[i << 1 | 1];
}

void down(int i, int l, int r) {
    if (!tag[i]) return;
    int mid = (l + r) >> 1;
    int left = i << 1;
    int right = i << 1 | 1;
    tag[left] = !tag[left];
    s[left] = (mid - l + 1) - s[left];
    tag[right] = !tag[right];
    s[right] = (r - mid) - s[right];
    tag[i] = 0;
}

void update(int i, int l, int r, int ul, int ur) {
    if (ul <= l && r <= ur) {
        tag[i] = !tag[i];
        s[i] = (r - l + 1) - s[i];
        return;
    }
    down(i, l, r);
    int mid = (l + r) >> 1;
    if (ul <= mid) {
        update(i << 1, l, mid, ul, ur);
    }
    if (ur > mid) {
        update(i << 1 | 1, mid + 1, r, ul, ur);
    }
    pushup(i);
}

int query(int i, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && qr >= r) {
        return s[i];
    }
    down(i, l, r);
    int mid = (l + r) >> 1;
    int L = query(i << 1, l, mid, ql, qr);
    int R = query(i << 1 | 1, mid + 1, r, ql, qr);
    return L + R;
}

int main(){
    int n, m;
    cin >> n >> m;
    while (m--) {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0) {
            update(1, 1, n, a, b);
        }
        else {
            cout << query(1, 1, n, a, b) << endl;
        }
    }
    return 0;
}