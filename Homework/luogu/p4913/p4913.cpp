#include <bits/stdc++.h>
using namespace std;

struct node {
    int l, r;
}t[1000005];

int dfs(int id) {
    if (id == 0) {
        return 0;
    }
    return 1 + max(dfs(t[id].l), dfs(t[id].r));
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i].l >> t[i].r;
    }
    cout << dfs(1) << endl;
    return 0;
}