#include <bits/stdc++.h>
using namespace std;

int s[205], vis[205], dis[205];
int ans = -1;
queue <int> q;

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	q.push(a);
	vis[a] = 1;
	dis[a] = 0;
	while (!q.empty()) {
		int id = q.front();
		q.pop();
		if (id == b) {
			cout << dis[id];
			return 0;
		}
		int up = id + s[id], down = id - s[id];
		if (up >= 1 && up <= n && vis[up] != 1) {
			vis[up] = 1;
			dis[up] = dis[id] + 1;
			q.push(up);
		}
		if (down >= 1 && down <= n && vis[down] != 1) {
			vis[down] = 1;
			dis[down] = dis[id] + 1;
			q.push(down);
		}
	}
	cout << -1;
	return 0;
}

