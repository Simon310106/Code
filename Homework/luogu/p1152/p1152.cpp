#include <bits/stdc++.h>
using namespace std;

int a[1050];
int num[1050];

int main(){
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        num[i] = abs(a[i + 1] - a[i]);
        cnt++;
    }
    sort(num, num + cnt);
    for (int i = 1; i <= n - 1; i++) {
        if (num[i - 1] != i) {
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly";
    return 0;
}