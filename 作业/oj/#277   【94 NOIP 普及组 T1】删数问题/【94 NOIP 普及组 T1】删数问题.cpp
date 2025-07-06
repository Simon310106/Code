#include <bits/stdc++.h>
using namespace std;

int num[300];
string a;

int main(){
    int k = 0, cnt = 0;
    cin >> a;
    cin >> k;
    int len = a.length();
    for (int i = 0; i < len; i++) {
        num[i] = a[i] - '0';
    }
    cnt = 0;
    int znum = 0;
    int n = len - k;
    int f = 0;
    for (int i = 0; i < len; i++) {
        if (num[i] > 0) {
            znum++;
        }
    }
    if (znum > k) {
        while (cnt < k) {
            int f = 0;
            for (int i = 0; i < len - 1; i++) {
                if (num[i] > num[i + 1]) {
                    f = 1;
                    for (int j = i; j < len - 1; j++) {
                        num[j] = num[j + 1];
                    }
                    num[len - 1] = -1;
                    len--;
                    cnt++;
                    if (cnt >= k) {
                        break;
                    }
                    break;
                }
            }
            if (f == 0) {
                break;
            }
        }
        if (cnt < k) {
            len -= (k - cnt);
        }
        int s = 0;
        for (int i = 0; i < len; i++) {
            if (num[i] > 0) {
                s = i;
                break;
            }
        }
        for (int i = s; i < len; i++) {
            cout << num[i];
        }
    }
    else {
        cout << 0;
    }
    return 0;
}