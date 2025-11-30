#include <bits/stdc++.h>
using namespace std;

int a[105];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                i--;
                n--;
            }
        }
    }
    sort(a, a + n);
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}