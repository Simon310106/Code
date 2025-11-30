#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int t[N], s[105];

int main(){
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t, t + n);
    int j = 1, time = 0;
    for (int i = 0; i < n; i++) {
        if (j > r) {
            j = 1;
        }
        s[j] += t[i];
        time += s[j];
        j++;
    }
    cout << time;
    return 0;
}