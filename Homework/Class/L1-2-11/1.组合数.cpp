#include <bits/stdc++.h>
using namespace std;

long long a, b;

long long C(long long n, long long m) {
    long long ans = 1;
    for (long long i = 1; i <= n; i++) {
        ans *= i;
    }
    for (long long i = 1; i <= m; i++) {
        ans /= i;
    }
    for (long long i = 1; i <= n - m; i++) {
        ans /= i;
    }
    return ans;
}

int main(){
	cin >> a >> b;
    cout << C(a, b);
//	system("pause");
	return 0;
}
