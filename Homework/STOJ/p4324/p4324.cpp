#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int fa[1005];
vector<int> g[1005];

int main(){
	cin >> n;
	memset(fa, -1, sizeof(fa));
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		fa[y] = x;
		if (fa[x] == -1) {
			fa[x] = 0;
		}
	}
	for (int i = 1; i <= 1000; i++) {
		if (fa[i] == 0) {
			cout << i << endl;
			break;
		}
	}
	
	int ma = 0, id = 0;
	for (int i = 1; i <= 1000; i++) {
		if (g[i].size() >= ma) {
			id = i;
			ma = g[i].size();
		}
	}
	cout << id << endl;
	sort (g[id].begin(), g[id].end());
	for (int i = 0; i < g[id].size(); i++) {
		cout << g[ma][i] << " ";
	}
	
	return 0;
}

