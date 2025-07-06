#include <bits/stdc++.h>
using namespace std;

queue<int> q1, q2;
int vis[410][410], ans[410][410];
int dx[] = {-2, -2, 2, 2, 1, -1, 1, -1};
int dy[] = {-1, 1, -1, 1, 2, -2, -2, 2};

int main(){
	memset(ans, -1, sizeof(ans));
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	q1.push(x);
	q2.push(y);
	ans[x][y] = 0;
	vis[x][y] = 1;
	while(!q1.empty()) {
		for (int i = 0; i < 8; i++) {
			int nx = q1.front() + dx[i];
			int ny = q2.front() + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m && vis[nx][ny] == 0) {
				vis[nx][ny]= 1;
				ans[nx][ny] = ans[q1.front()][q2.front()] + 1;
				q1.push(nx);
				q2.push(ny);
			}
		}
		q1.pop();
		q2.pop(); 
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

