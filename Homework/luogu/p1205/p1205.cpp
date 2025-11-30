#include <bits/stdc++.h>
using namespace std;

int a[15][15], b[15][15], c[15][15];

bool zh(int n) {
    bool f = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != c[i][j]) {
                f = 0;
            }
        }
    }
    if (f) {
        return 1;
    }
// ---------------------------------------------------------
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[j][n - i + 1] = a[i][j];
            }
        }
        f = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != b[i][j]) {
                    f = 0;
                }
            }
        }
        if (f) {
            return 1;
        }
// ---------------------------------------------------------
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[j][i] = b[i][j];
            }
        }
        f = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != c[i][j]) {
                    f = 0;
                }
            }
        }
        if (f) {
            return 1;
        }
// ---------------------------------------------------------
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                b[j][i] = a[i][j];
            }
        }
        f = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j] != c[i][j]) {
                    f = 0;
                }
            }
        }
        if (f) {
            return 1;
        }
// ---------------------------------------------------------
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++)
        }
    }
    

}

int main(){
    
    return 0;
}