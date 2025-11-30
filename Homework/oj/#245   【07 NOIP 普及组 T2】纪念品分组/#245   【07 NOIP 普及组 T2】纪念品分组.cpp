#include <bits/stdc++.h>
using namespace std;

int t[30005], ans;

int main(){
    int w, n;
    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t, t + n);
    int i = 0, j = n - 1;
    while (i <= j) {
        if (t[i] + t[j] > w) {
            ans++;
            j--;
        }
        else if (t[i] + t[j] <= w || i == j) {
            ans++;
            i++;
            j--;
        }
    }
    cout << ans;
    return 0;
}