#include <bits/stdc++.h>
using namespace std;

int ans = 0;
bool check(int a) {
    while(a % 2 == 0) {
        a /= 2;
    }
    while(a % 5 == 0) {
        a /= 5;
    }
    return a == 1;
}

int main(){
    int l, r;
    cin >> l >> r;
    while (l <= r) {
        if (check(l)) {
            ans++;
        }
        l++;
    }
    cout << ans;
    return 0;
}