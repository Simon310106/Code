#include <bits/stdc++.h>
using namespace std;

int ans;

int main(){
    int n;
    cin >> n;
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n -= 1;
        }
        ans++;
    }
    cout << ans;
    return 0;
}