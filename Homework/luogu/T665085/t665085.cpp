#include <bits/stdc++.h>
using namespace std;

int n, y, s, t;
int a[1005];

int main(){
    cin >> n >> y >> s >> t;
    a[1] = y;
    for (int i = 2; i <= n; i++) {
        a[i] = a[i - 1] + t;
    }
    int now = 0;
    for (int i = 1; i <= n; i++) {
        int start = now;
        int end = now + s;
        bool found = true;
        for (int j = start; j <= end; j++) {
            for (int k = 1; k <= n; k++) {
                if (j == a[k]) {
                    found = false;
                    break;
                }
            }
        }
        if (found) {
            cout << "Yes" << endl;
            return 0;
        }
        now = end;
    }
    cout << "No" << endl;
    return 0;
}