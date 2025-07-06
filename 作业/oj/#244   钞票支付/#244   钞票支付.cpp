#include <bits/stdc++.h>
using namespace std;

int a[10] = {1, 5, 10, 20, 100, 200}, ans;

int main(){
    int x;
    cin >> x;
    for (int i = 5; i >= 0; i--) {
        ans += x / a[i];
        x %= a[i];
    }
    cout << ans;
    return 0;
}