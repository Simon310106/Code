#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N], ma;

bool cmp(int a, int b) {
    return a > b;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort (a, a + n, cmp);
    n = min(n, 32);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ma = max(ma, (a[i] & a[j]));
        }
    }
    cout << ma;
    return 0;
}