#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
stack<int> pos;
bool del[1000005];

int main(){
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    vector<ull> hash(max(n, m) + 1, 0);
    vector<ull> base(max(n, m) + 1, 0);
    base[0] = 1;
    for (int i = 1; i <= m; i++) {
        base[i] = base[i - 1] * 1313;
    }
    hash[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < n; i++) {
        hash[i] = hash[i - 1] * 1313 + (s[i] - 'a' + 1);
    }
    ull key = 0;
    for (int i = 0; i < m; i++) {
        key = key * 1313 + (p[i] - 'a' + 1);
    }
    for (int l = 0; l <= n - m + 1; l++) {
        ull ans = hash[l + m - 1];
        if (l > 0) {
            ans = ans - hash[l - 1] * base[m];
        }
        if (s[l] == p[0]) {
            pos.push(l);
        }
        if (ans == key) {
            pos.pop();
            for (int i = l; i <= l + m; i++) {
                del[i] = 1;
            }
            while (!pos.empty()) {
                int nxt = pos.top();
                int cnt = 0;
                while (cnt < m) {
                    if (del[nxt]) {
                        nxt++;
                        continue;
                    }
                    if (s[nxt] == p[cnt]) {
                        cnt++;
                        nxt++;
                    }
                }
            }
        }
    }
    return 0;
}