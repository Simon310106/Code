#include <bits/stdc++.h>
using namespace std;

int a[100005];
int counts[1000005];
int cnt[1000005];
int n, ma;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        ma = max(ma, a[i]);
    }
    for (int i = 1; i <= ma; i++) {
        if (cnt[i]) {
            for (int j = i; j <= ma; j += i) {
                counts[j] += cnt[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << counts[a[i]] - 1 << "\n";
    }

    return 0;
}