#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long h[N], st[N], top;
long long L[N], R[N];

struct Frac {
    long long N, D;
    const bool operator < (const Frac &other) const {
        return N * other.D < D * other.N;
    }
};

Frac calc(int i, int j, int k) {
    long long base = abs(i - k); // 整数部分距离
    long long n = h[i] - h[k];
    long long d = h[j] - h[k];
    long long g = gcd(base * d + n, d);
    return {(base * d + n) / g , d / g};
}

int main(){
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++) {
        while (top && h[st[top]] < h[i]) {
            R[st[top]] = i;
            top--;
        }
        if (top) L[i] = st[top];
        st[++top] = i;
    }
    Frac ans = {0, 1};
    for (int i = 1; i <= n; i++) {
        if (L[i]) {
            Frac t = calc(i, L[i], L[i] + 1);
            ans = max(ans, t);
        }
        if (R[i]) {
            Frac t = calc(i, R[i], R[i] - 1);
            ans = max(ans, t);
        }
    }
    if (ans.N == 0) cout << 0;
    else if (ans.D == 1) cout << ans.N;
    else cout << ans.N << '/' << ans.D;
    return 0;
}