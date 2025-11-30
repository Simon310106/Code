#include <bits/stdc++.h>
using namespace std;

char a[105][105];

int number(int i, int j) {
    int ans = 0;
    if (a[i][j + 1] == '*') {
        ans++;
    }
    if (a[i][j - 1] == '*') {
        ans++;
    }
    if (a[i + 1][j] == '*') {
        ans++;
    }
    if (a[i - 1][j] == '*') {
        ans++;
    }

    if (a[i + 1][j - 1] == '*') {
        ans++;
    }
    if (a[i + 1][j + 1] == '*') {
        ans++;
    }
    if (a[i - 1][j + 1] == '*') {
        ans++;
    }
    if (a[i - 1][j - 1] == '*') {
        ans++;
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '?') {
                a[i][j] = char(number(i, j) + '0');
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    

    return 0;
}