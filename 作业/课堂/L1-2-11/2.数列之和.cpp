#include <bits/stdc++.h>
using namespace std;

double S(int n) {
    double ans = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = 0;
        for (int j = 1; j <= i; j++) {
            temp += j;
        }
        ans += 1.0 / temp;
    }
    return ans;
}

int main(){
    int n;
	cin >> n;
    cout << S(n);
//	system("pause");
	return 0;
}
