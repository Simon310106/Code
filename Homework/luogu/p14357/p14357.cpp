#include <bits/stdc++.h>
using namespace std;

int a[1000005];

int main(){
    string s;
    cin >> s;
    int len = s.length(), cnt = 1;
    while (len--) {
        if (s[len] >= '0' && s[len] <= '9') {
            a[cnt++] = s[len] - '0';
        }
    }
    cnt--;
    sort(a + 1, a + cnt + 1);
    for (int i = cnt; i >= 1; i--) {
        cout << a[i];
    }
    return 0;
}