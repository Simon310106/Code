#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;

int main(){
	freopen("uniform.in", "r", stdin);
	freopen("uniform.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    int a = m, b = 0, ans = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '1') {
    		if (a) a--;
    		else if (b) b--;
    		else ans++;
		}
		if (s[i] == '2') {
			if (b) b--;
			else ans++;
		}
		if (s[i] == '0') {
			a = m;
			b = ans; 
		}
	}
	cout << ans << endl;
    return 0;
}
