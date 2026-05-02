#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int q1[N], h1, t1;
int q2[N], h2, t2;
int ans;

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1;
    for (int i = 1; i <= n; i++) {
        while (h1 < t1 && a[q1[t1 - 1]] <= a[i]) {
            t1--;
        }
        q1[t1++] = i;
        while (h2 < t2 && a[q2[t2 - 1]] >= a[i]) {
            t2--;
        }
        q2[t2++] = i;
        while (h1 < t1 && h2 < t2 && a[q1[h1]] - a[q2[h2]] > k) {
            if (q1[h1] == l) h1++;
            if (q2[h2] == l) h2++;
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << endl;
    return 0;
}