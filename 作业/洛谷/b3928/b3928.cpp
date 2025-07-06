#include <bits/stdc++.h>
using namespace std;

int u[500005], v[500005];

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(u, u + n);
    sort(v, v + n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (u[i] >= v[j]) {
            j++;
            ans++;
        } 
    }
    cout << ans;
    return 0;
}