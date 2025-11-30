#include <bits/stdc++.h>
using namespace std;

int a[100005], dp1[100005], dp2[100005];
int len = 1, len2 = 1;

int main() {
    int n = 0;
    while (cin >> a[n]) n++;
    
    dp1[1] = a[0];
    dp2[1] = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] <= dp1[len]) {
            dp1[++len] = a[i];
        }
        else {
            dp1[upper_bound(dp1 + 1, dp1 + len + 1, a[i], greater<int>()) - dp1] = a[i];
        }
    }
    cout << len << endl;

    for (int i = 0; i < n; i++) {
        if (dp2[len2] < a[i]) {
            dp2[++len2] = a[i];
        }
        else {
            dp2[lower_bound(dp2 + 1, dp2 + len2 + 1, a[i]) - dp2] = a[i];
        }
    }
    cout << len2;
    return 0;
}

