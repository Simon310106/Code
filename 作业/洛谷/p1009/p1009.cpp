#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unsigned long long s = 0;
    for (int i = 1; i <= n; i++) {
        unsigned long long t = 1;
        for (int j = 1; j <= i; j++) {
            t *= j;
        }
        s += t;
    }
    cout << s;
    return 0;
}