#include <bits/stdc++.h>
using namespace std;
 
int n, a[10005], b[10005], g[10005], k[10005], x, y;

int main(){
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }
    cin >> x >> y;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (x >= a[i] && y >= b[i] && x <= a[i] + g[i] && y <= b[i] + k[i]) {
            ans = i + 1;
        }
    }
    cout << ans;
//	system("pause");
	return 0;
}
