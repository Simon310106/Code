#include <bits/stdc++.h>
using namespace std;

int a[100050], b[100050], sum;

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= m; i++) {
        int l = 0, r = n + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] <= b[i]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        if (b[i] <= a[1]) {
            sum += a[1] - b[i];
        }
        else {
            sum += min(abs(a[l - 1] - b[i]), abs(a[l] - b[i]));
        }
    }
    cout << sum;
    return 0;
}