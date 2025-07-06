#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
    if (n == 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int change(int n) {
    int a, b;
    a = n % 10;
    b = n / 10;
    return (b + a * 10);
}

int main(){
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (prime(i) && prime(change(i))) {
            cout << i << endl;
        }
    }

    return 0;
}