#include <bits/stdc++.h>
using namespace std;

int g[100], f[100];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + 1 + g[i - 1] + 1 + f[i - 1];
        g[i] = f[i - 1] + 1 + f[i - 1];
    }
    cout << f[n] << endl;
    return 0;
}