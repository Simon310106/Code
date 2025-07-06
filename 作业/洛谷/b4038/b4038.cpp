#include <bits/stdc++.h>
using namespace std;

int a[10005], sum[10005];

int main(){
    int s;
    cin >> s;
    for (int t = 0; t < s; t++) {
        int n;
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i == 0) {
                sum[i] = a[i];
            }
            else {
                sum[i] = sum[i - 1] + a[i];
            }
        }
        bool flag = 0;
        for (int i = 0; i < n - 1; i++) {
            if (sum[i] == sum[n - 1] - sum[i]) {
                cout << "Yes\n";
                flag = 1;
                break;
            }
        }
        if (!flag) {
            cout << "No\n";
        }
    }
    return 0;
}