#include <bits/stdc++.h>
using namespace std;

int n, ans;
int a[10005], r[10005];

void msort(int s, int t) {
    if (s == t) {
        return;
    }
    int mid = (s + t) >> 1;
    msort(s, mid);
    msort(mid + 1, t);
    int i = s, j = mid + 1, k = s;
    while (i <= mid && j <= t) {
        if (a[i] <= a[j]) {
            r[k] = a[i];
            i++;
            k++;
        }
        else {
            ans += mid - i + 1;
            r[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        r[k] = a[i];
        i++;
        k++;
    }
    while (j <= t) {
        r[k] = a[j];
        k++;
        j++;
    }
    for (int x = s; x <= t; x++) {
        a[x] = r[x];
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    msort(1, n);
    cout << ans;
    return 0;
}