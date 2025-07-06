#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        ans += 1;
        ans *= 2;
    }
    cout << ans;
    return 0;
}