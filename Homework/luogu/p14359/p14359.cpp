#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int a[500005], ans, pre;

int main(){
    int n, k;
    cin >> n >> k;
    unordered_set<int> sum;
    sum.insert(0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre ^= a[i];
        if (sum.count(pre ^ k)) {
            pre = 0;
            sum.clear();
            sum.insert(0);
            ans++;
        }
        else {
            sum.insert(pre);
        }
    }
    cout << ans;
    return 0;
}