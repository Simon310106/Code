#include <bits/stdc++.h>
using namespace std;

int m[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, t[2300] = {6};

int main(){
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= 2222; i++) {
        int s = i;
        while (s != 0) {
            t[i] = t[i] + m[s % 10];
            s /= 10;
        }
    }
    for (int i = 0; i < 1111; i++) {
        for (int j = 0; j < 1111; j++) {
            int a = i, b = j, c = i + j;
            if (t[a] + t[b] + t[c] + 4 == n) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}