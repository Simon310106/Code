#include <bits/stdc++.h>
using namespace std;

string a, b;

void dfs (int x, int y, int l, int r) {
    if (x > y || l > r) {
        return;
    }
    for (int i = x; i <= y; i++) {
        if (a[i] == b[l]) {
            dfs(x, i - 1, l + 1, l + i - x);
            dfs(i + 1, y, l + i - x + 1, r);
            cout << a[i];
        }
    }
}

int main(){
    cin >> a >> b;
    int n = a.size();
    dfs(0, n - 1, 0, n - 1);
    return 0;
}