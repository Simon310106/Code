#include <bits/stdc++.h>
using namespace std;

map<string, bool> m;
char trans[20][2];
queue <string> q;
int ans = 1;

int main(){
//	ios::sync_with_stdio(0); 
//	cin.tie(0);
	string n;
	int k;
	cin >> n >> k;
	m[n] = 1;
	q.push(n);
	for (int i = 1; i <= k; i++) {
		cin >> trans[i][0] >> trans[i][1];
	}
	for (int i = 0; i < n.size(); i++) {
		int tmp = 1;
		for (int j = 1; j <= k; j++) {
			if (n[i] == trans[j][0]) {
				tmp++;
			}
		}
		ans *= tmp;
	}
	cout << ans;
	
	return 0;
}
