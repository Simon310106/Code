#include <bits/stdc++.h>
using namespace std;

int a[35];
long long n = 0, sum = 0;

int main(){
    while (cin >> a[n++]);
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    sum *= pow(2, n - 2);
    cout << sum;

    return 0;
}