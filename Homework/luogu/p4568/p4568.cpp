#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int N = 5e4 + 5;
vector<PII> g[N];
int dist[10005];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int s, t;
    cin >> s >> t;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    queue<PII> q;
    q.push({0, s});
    dist[s] = 
    return 0;
}