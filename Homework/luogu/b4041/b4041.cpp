#include <bits/stdc++.h>
using namespace std;

int a[105];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = l - 1; j < r; j++) {
            for (int k = j + 1; k < r; k++) {
                if (a[j] > a[k]) {
                    swap(a[j], a[k]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}