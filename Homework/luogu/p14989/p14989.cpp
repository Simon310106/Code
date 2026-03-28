#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+5;
int n, q;
int p[MAXN], R[MAXN], L[MAXN];
int st[MAXN][20];
int lg2[MAXN] = {-1};
int a[MAXN], pos[MAXN];
stack<int> sl;
stack<int> sr;

int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
        st[i][0] = p[i];
        lg2[i] = lg2[i / 2] + 1;
    }
    for (int j = 1; j <= lg2[n]; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        while (!sl.empty() && sl.top() < p[i]) {
            sl.pop();
        }
        
        L[i] = sl.size();
        sl.push(p[i]);
    }
    for (int i = n; i >= 1; i--) {
        while (!sr.empty() && sr.top() < p[i]) {
            sr.pop();
        }
        
        R[i] = sr.size();
        sr.push(p[i]);
    }
    while (q--) {
        int k;
        cin >> k;
        int l = INT_MAX, r = -1;
        for (int i = 1; i <= k; i++) {
            int x;
            cin >> x;
            l = min(l, x);
            r = max(r, x);
        }
        int t = r - l + 1;
        int mid = max(st[l][lg2[t]], st[r - (1 << lg2[t]) + 1][lg2[t]]);
        cout << L[pos[mid]] + R[pos[mid]] + 1 << endl;
    }

    return 0;
}