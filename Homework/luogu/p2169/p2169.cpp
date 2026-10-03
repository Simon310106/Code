#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> g[N], scc[N];
stack<int> st;
int n, m;
int dfn[N], low[N], belong[N], sccCnt, idx;

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    for (int v : g[u]) {
        if (dfn[v] == 0) {
            tarjan(v);
            
        }
    }
}

int main(){
    
    return 0;
}