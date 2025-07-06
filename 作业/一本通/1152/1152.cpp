#include <bits/stdc++.h>
using namespace std;

double ma(int a, int b, int c) {
    if (a < b) {
        a = b;
    }
    if (a < c) {
        a = c;
    }
    return a;
}

int main(){
	int a, b, c;
    cin >> a >> b >> c;
    double m = ma(a, b, c) / (ma(a + b, b, c) * ma(a, b, b + c)) * 1.0;
    cout << fixed << setprecision(3) << m;
	return 0;
}
