#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
double s1[4*N], s2[4*N], tag[4*N], a[N];
// s1:和    s2:平方和

void up(int i) {
    s1[i] = s1[i << 1] + s1[i << 1 | 1];
    s2[i] = s2[i << 1] + s2[i << 1 | 1];
}

void build(int i, int l, int r) {
    if (l == r) {
        s1[i] = a[l];
        s2[i] = a[l] * a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    up(i);
}

void down(int i, int l, int r) {
    if (!tag[i]) return;
    int mid = (l + r) >> 1;
    int left = i << 1;
    int right = i << 1 | 1;
    s2[left] += 2.0 * tag[i] * s1[left] + (mid - l + 1) * tag[i] * tag[i] * 1.0;
    s1[left] += (mid - l + 1) * tag[i] * 1.0;
    tag[left] += tag[i];
    s2[right] += 2.0 * tag[i] * s1[right] + (r - mid) * tag[i] * tag[i] * 1.0;
    s1[right] += (r - mid) * tag[i] * 1.0;
    tag[right] += tag[i];
    tag[i] = 0;
}

void update(int i, int l, int r, int ul, int ur, double v) {
    if (ul <= l && r <= ur) {
        s2[i] += 2.0 * v * s1[i] + (r - l + 1) * v * v * 1.0;
        s1[i] += (r - l + 1) * v * 1.0; 
        tag[i] += v;
        return;
    }
    down(i, l, r);
    int mid = (l + r) >> 1;
    if (ul <= mid) update(i << 1, l, mid, ul, ur, v);
    if (ur > mid)  update(i << 1 | 1, mid + 1, r, ul, ur, v);
    up(i);
}

double query(int i, int l, int r, int ql, int qr, double s[]) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && qr >= r) return s[i];
    down(i, l, r);
    int mid = (l + r) >> 1;
    double L = query(i << 1, l, mid, ql, qr, s);
    double R = query(i << 1 | 1, mid + 1, r, ql, qr, s);
    return L + R;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int opr, x, y;
        cin >> opr >> x >> y;
        if (opr == 1) {
            double k;
            cin >> k;
            update(1, 1, n, x, y, k);
        }
        else if (opr == 2) {
            double sum = query(1, 1, n, x, y, s1);
            cout << fixed << setprecision(4) << sum / (y - x + 1) * 1.0 << endl;
        }
        else {
            double avg = query(1, 1, n, x, y, s1) / (y - x + 1) * 1.0;
            double sum = query(1, 1, n, x, y, s2);
            cout << fixed << setprecision(4) << sum / (y - x + 1) * 1.0 - avg * avg << endl;
        }
    }
    return 0;
}