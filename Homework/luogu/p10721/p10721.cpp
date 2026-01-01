#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n, m, a[50], f[100005];
string s;

signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= m; j++) {
            f[j] = max(f[j], f[j - i] + a[i]);
        }
    }
    s = s + "#$%";
    int i = 0, k = 0, ans = 0;
    while (i <= m) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
            i += 3;
			k++; 
        }
        else {
        	i++;
        	ans += f[k];
			k = 0; 
		}
    } 
    cout << ans;
    return 0;
}
