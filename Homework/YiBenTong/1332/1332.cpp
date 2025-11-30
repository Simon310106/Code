#include <bits/stdc++.h>
using namespace std;

queue <int> a, b;

int main(){
    int n, m;
    int k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        a.push(i);
    }
    for (int i = 1; i <= m; i++) {
        b.push(i);
    }
    for (int i = 1; i <= k; i++) {
        int x = a.front();
        int y = b.front();
        cout << x << " " << y << endl;
        a.push(x);
        b.push(y);
        a.pop();
        b.pop();
    }
    return 0;
}