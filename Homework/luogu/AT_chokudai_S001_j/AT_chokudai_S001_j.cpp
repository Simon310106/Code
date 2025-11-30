#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAXN = 100010;
ll r[MAXN], a[MAXN], ans;

void msort(ll s, ll t) {
    if (s == t) {
        return;
    }
    ll mid = (s + t) >> 1;
    msort(s, mid);
    msort(mid + 1, t);
    ll i = s, j = mid + 1, k = s;
    while (i <= mid && j <= t) {
        if (a[i] <= a[j]) {
            r[k] = a[i];
            i++;
            k++;
        }
        else {
            ans += mid - i + 1;
            r[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid) {
        r[k] = a[i];
        k++;
        i++;
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
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    msort(1, n);
    cout << ans;
    return 0;
}