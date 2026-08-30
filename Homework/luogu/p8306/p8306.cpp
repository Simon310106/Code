#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 5;
int trie[N][62], p[N], idx;

int getV(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    else return c - 'a' + 36;
}

void insert(string s) {
    p[0]++;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        int path = getV(s[i]);
        if (trie[cur][path] == 0) trie[cur][path] = ++idx;
        cur = trie[cur][path];
        p[cur]++;
    }
}

int prefind(string s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        int path = getV(s[i]);
        if (trie[cur][path] == 0) return 0;
        cur = trie[cur][path];
    }
    return p[cur];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        memset(p, 0, sizeof p);
        memset(trie, 0, sizeof trie);
        idx = 0;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            insert(s);
        }
        for (int i = 1; i <= q; i++) {
            string s;
            cin >> s;
            printf("%d\n", prefind(s));
        }
    }
    return 0;
}