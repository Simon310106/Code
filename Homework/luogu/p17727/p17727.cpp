#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

signed main(){
    cin >> n >> m;
    int k = (n + 1) / 2;
    if (k % 2 == 1 && (m == k || m == k + 1)) {
        cout << 0 << endl;
        return 0;
    }
    int id = (m + 1) / 2;
    if (id > (k / 2)) {
        cout << k - id + 1 << endl;
        return 0;
    }
    if (id <= (k / 2)) {
        cout << id << endl;
        return 0;
    }
    return 0;
}