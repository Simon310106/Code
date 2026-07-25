#include <bits/stdc++.h>
using namespace std;

int p1[100005], p2[100005];
int a[100005];
vector<int> dp;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p1[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p2[i];
        a[p1[i]] = p2[i];
    }
    for (int i = 1; i <= n; i++) {
        int pos = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if (pos == dp.size()) {
            dp.push_back(a[i]);
        }
        else {
            dp[pos] = a[i];
        }
    }
    cout << dp.size();
    return 0;
}
