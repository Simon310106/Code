#include <bits/stdc++.h>
using namespace std;

int a[20];

int main(){
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans *= a[i] / __gcd(ans, a[i]);
	}
    cout << ans;
    return 0;
}
