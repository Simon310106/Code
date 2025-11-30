#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e+5;
int a[MAXN];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        bool f = 1;
        int t = a[i];
        for (int j = 2; j * j <= t; j++) {
            if (t % j == 0) {
                f = 0;
                break;
            }
        }
        if (f && t != 1) {
            cout << t << " ";
        }
    }
    return 0;
}