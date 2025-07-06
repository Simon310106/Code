#include <bits/stdc++.h>
using namespace std;

int a[10000];
string ans[30500];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char t;
        cin >> t;
        a[i] = t - '0';
    }
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            if (a[i] == 0) {
                ans[0] += "XXX";
                ans[1] += "X.X";
                ans[2] += "X.X";
                ans[3] += "X.X";
                ans[4] += "XXX";
            }
            else if (a[i] == 1) {
                ans[0] += "..X";
                ans[1] += "..X";
                ans[2] += "..X";
                ans[3] += "..X";
                ans[4] += "..X";
            }
            else if (a[i] == 2) {
                ans[0] += "XXX";
                ans[1] += "..X";
                ans[2] += "XXX";
                ans[3] += "X..";
                ans[4] += "XXX";
            }
            else if (a[i] == 3) {
                ans[0] += "XXX";
                ans[1] += "..X";
                ans[2] += "XXX";
                ans[3] += "..X";
                ans[4] += "XXX";
            }
            else if (a[i] == 4) {
                ans[0] += "X.X";
                ans[1] += "X.X";
                ans[2] += "XXX";
                ans[3] += "..X";
                ans[4] += "..X";
            }
            else if (a[i] == 5) {
                ans[0] += "XXX";
                ans[1] += "X..";
                ans[2] += "XXX";
                ans[3] += "..X";
                ans[4] += "XXX";
            }
            else if (a[i] == 6) {
                ans[0] += "XXX";
                ans[1] += "X..";
                ans[2] += "XXX";
                ans[3] += "X.X";
                ans[4] += "XXX";
            }
            else if (a[i] == 7) {
                ans[0] += "XXX";
                ans[1] += "..X";
                ans[2] += "..X";
                ans[3] += "..X";
                ans[4] += "..X";
            }
            else if (a[i] == 8) {
                ans[0] += "XXX";
                ans[1] += "X.X";
                ans[2] += "XXX";
                ans[3] += "X.X";
                ans[4] += "XXX";
            }
            else if (a[i] == 9) {
                ans[0] += "XXX";
                ans[1] += "X.X";
                ans[2] += "XXX";
                ans[3] += "..X";
                ans[4] += "XXX";
            }
        }
        else {
            if (a[i] == 0) {
                ans[0] += "XXX.";
                ans[1] += "X.X.";
                ans[2] += "X.X.";
                ans[3] += "X.X.";
                ans[4] += "XXX.";
            }
            else if (a[i] == 1) {
                ans[0] += "..X.";
                ans[1] += "..X.";
                ans[2] += "..X.";
                ans[3] += "..X.";
                ans[4] += "..X.";
            }
            else if (a[i] == 2) {
                ans[0] += "XXX.";
                ans[1] += "..X.";
                ans[2] += "XXX.";
                ans[3] += "X...";
                ans[4] += "XXX.";
            }
            else if (a[i] == 3) {
                ans[0] += "XXX.";
                ans[1] += "..X.";
                ans[2] += "XXX.";
                ans[3] += "..X.";
                ans[4] += "XXX.";
            }
            else if (a[i] == 4) {
                ans[0] += "X.X.";
                ans[1] += "X.X.";
                ans[2] += "XXX.";
                ans[3] += "..X.";
                ans[4] += "..X.";
            }
            else if (a[i] == 5) {
                ans[0] += "XXX.";
                ans[1] += "X...";
                ans[2] += "XXX.";
                ans[3] += "..X.";
                ans[4] += "XXX.";
            }
            else if (a[i] == 6) {
                ans[0] += "XXX.";
                ans[1] += "X...";
                ans[2] += "XXX.";
                ans[3] += "X.X.";
                ans[4] += "XXX.";
            }
            else if (a[i] == 7) {
                ans[0] += "XXX.";
                ans[1] += "..X.";
                ans[2] += "..X.";
                ans[3] += "..X.";
                ans[4] += "..X.";
            }
            else if (a[i] == 8) {
                ans[0] += "XXX.";
                ans[1] += "X.X.";
                ans[2] += "XXX.";
                ans[3] += "X.X.";
                ans[4] += "XXX.";
            }
            else if (a[i] == 9) {
                ans[0] += "XXX.";
                ans[1] += "X.X.";
                ans[2] += "XXX.";
                ans[3] += "..X.";
                ans[4] += "XXX.";
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}