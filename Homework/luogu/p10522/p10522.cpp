#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int f[N];

int main(){
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (f[x]) {
            f[i] = f[x];
        }
        f[x] = i;
    }
    for (int i = 0; f[i]; i = f[i]) {
        cout << f[i] << " ";
    }
    return 0;
}