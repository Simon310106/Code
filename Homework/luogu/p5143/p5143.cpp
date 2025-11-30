#include <bits/stdc++.h>
using namespace std;

struct hke{
    int x, y, z;
}a[50005];

bool cmp(hke a, hke b) {
    return a.z < b.z;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a, a + n, cmp);
    double ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += sqrt(pow(a[i].x - a[i + 1].x, 2) + pow(a[i].y - a[i + 1].y, 2) + pow(a[i].z - a[i + 1].z, 2));
    }
    cout << fixed << setprecision(3) << ans;
    return 0;
}