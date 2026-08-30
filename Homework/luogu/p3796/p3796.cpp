#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int trie[N][26], fail[N], e[N], idx, times[N];
vector<int> g[N];
string s[151];

void insert(int p, string s) {
    int cur = 0;
    for (int i = 0; i < s.size();i++) {
        int path = s[i] - 'a';
        if (trie[cur][path] == 0) trie[cur][path] = ++idx;
        cur = trie[cur][path];
    }
    e[p] = cur;
}

void setfail() {
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (trie[0][i] > 0) q.push(trie[0][i]);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < 26; i++) {
            if (trie[cur][i] == 0) {
                trie[cur][i] = trie[fail[cur]][i];
            }
            else {
                fail[trie[cur][i]] = trie[fail[cur]][i];
                q.push(trie[cur][i]);
            }
        }
    }
}

void solve(int u) {
    for (auto v : g[u]) {
        solve(v);
        times[u] += times[v];
    }
}

int main(){
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        for (int i = 0; i <= idx; i++) {
            times[i] = 0;
            e[i] = 0;
            fail[i] = 0;
            for (int j = 0; j < 26; j++) {
                trie[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            insert(i, s[i]);
        }
        setfail();
        string p;
        cin >> p;
        for (int i = 0, cur = 0; i < p.size(); i++) {
            cur = trie[cur][p[i] - 'a'];
            times[cur]++;
        }
        for (int i = 1; i <= idx; i++) {
            g[fail[i]].push_back(i);
        }
        solve(0);
        int ma = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++) {
            ma = max(ma, times[e[i]]);
        }
        cout << ma << endl;
        for (int i = 1; i <= n; i++) {
            if (times[e[i]] == ma) {
                cout << s[i] << endl;
            }
        }
    }
    return 0;
}