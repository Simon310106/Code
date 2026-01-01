#include <bits/stdc++.h>
using namespace std;

struct edge {
    int v, w;
};

vector<edge> g[1005];
void addedge(int u, int v, int w) {
    g[u].push_back({v, w});
    g[v].push_back({u, w});
}

int main(){
    addedge(1, 2, 3);
    return 0;
}
