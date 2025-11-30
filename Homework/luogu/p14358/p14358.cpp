#include <bits/stdc++.h>
using namespace std;

struct node {
    int id, score;
}a[105];

bool cmp(node x, node y) {
    return x.score > y.score;
}

int g[20][20];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i].score;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    int i = 1, j = 1, cnt = 1;
    while (cnt <= n * m) {
        g[i][j++] = a[cnt++].score;
    }
    return 0;
}