#include <bits/stdc++.h>
using namespace std;

int n, m, d;
char a[1005][1005], b[1005][1005];

int rsp(char a, char b) {
    if (a == 'R') {
        if (b == 'S') {
            return 1;
        }
        else if (b == 'P') {
            return -1;
        }
        else {
            return 0;
 	   }
    }
    else if (a == 'S') {
        if (b == 'P') {
            return 1;
        }
        else if (b == 'R') {
            return -1;
        }
        else {
            return 0;
        }
    }
    else if (a == 'P') {
        if (b == 'R') {
            return 1;
        }
        else if (b == 'S') {
            return -1;
        }
        else {
            return 0;
        }
    }
}

int main(){
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < d; i++){
        memcpy(b, a, sizeof(a));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (j + 1 < n) {
                    if (rsp(a[j][k], a[j + 1][k]) == 1) {
                        b[j + 1][k] = a[j][k];
                    }
                    else if (rsp(a[j][k], a[j + 1][k]) == -1) {
                        b[j][k] = a[j + 1][k];
                    }
                }
                if (k + 1 < m) {
                    if (rsp(a[j][k], a[j][k + 1]) == 1) {
                        b[j][k + 1] = a[j][k];
                    }
                    else if (rsp(a[j][k], a[j][k + 1]) == -1) {
                        b[j][k] = a[j][k + 1];
                    }
                }

            }
        }
        memcpy(a, b, sizeof(a));
    }
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j];
        }
        if (i < n - 1) {
            cout << endl;
        }
    }
    return 0;
}
