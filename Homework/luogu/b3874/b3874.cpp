#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAXN = 3e+5 + 10;
ll a[MAXN], r[MAXN], ans;

void msort(int s, int t) {
    if (s == t) {
        return;
    }
    int mid = (s + t) >> 1;
    msort(mid + 1, t);
    msort(s, mid);
    int i = s, j = mid + 1, k = s;
    while (i <= mid && j <= t) {
        if (a[i] > a[j]) {
            r[k] = a[i];
            k++;
            i++;
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
        j++;
        k++;
    }
    for (int x = s; x <= t; x++) {
        a[x] = r[x];
    }
}


int main(){
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    msort(0, n - 1);
    cout << ans;
    return 0;
}