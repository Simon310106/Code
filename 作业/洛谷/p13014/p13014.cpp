#include <bits/stdc++.h>
using namespace std;

int a[100005];

int gcd(int a, int b) {
    if (a == 0 || b == 0) {
        return a + b;
    }
    return gcd(b, a % b);
}

int main(){
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int g = 0;
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++){
        g = gcd(g, a[i] - a[i - 1]);
    }
    for (int i = 1; i <= q; i++) {
        cout << gcd(g, a[1] + i) << endl;
    }
    return 0;
}