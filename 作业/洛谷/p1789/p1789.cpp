#include <bits/stdc++.h>
using namespace std;
 
int n, m, k, mc[150][150], ans;

int overstep(int a, int b, int n) {
    if (a < 1 || b < 1 || a > n || b > n) {
        return 0;
    }
    else {
        return 1;
    }
}

int main(){
	cin >> n >> m >> k;
    for (int i = 1; i <= m + k; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = -2; j <= 2; j++) {
            for (int k = -2; k <= 2; k++) {
                if ((i > m || abs(j) + abs(k) <= 2) && overstep(j + x, k + y, n)) {
                    mc[j + x][k + y] = 1;
                }
            }
            
        }
        
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mc[i][j] == 0) {
                ans++;
            }
        }
    }
    cout << ans;
//	system("pause");
	return 0;
}
