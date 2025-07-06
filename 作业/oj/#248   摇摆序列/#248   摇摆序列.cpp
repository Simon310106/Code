#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int START = 0, UP = 1, DOWN = 2;
    int state = START, ans = 1;
    for (int i = 2; i <= n; i++) {
        if (state == START) {
            if (a[i] > a[i - 1]) {
                state = UP;
                ans++;
            }
            else {
                state = DOWN;
                ans++;
            }
        }
        else if (state == UP) {
            if (a[i] < a[i - 1]) {
                state = DOWN;
                ans++;
            }
        }
        else {
            if (a[i] > a[i - 1]) {
                state = UP;
                ans++;
            }
        }
    }
    cout << ans; 
    return 0;
}