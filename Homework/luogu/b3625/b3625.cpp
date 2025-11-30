#include <iostream>
#include <queue>
using namespace std;

char map[150][150];
bool flag[150][150];
int n, m;
queue<pair<int, int> > q;
pair<int, int> p;

bool bfs() {
	q.push(make_pair(1, 1));
	while (!q.empty()) {
		p = q.front();
		if (p.first == n && p.second == m) {
			return true;
		}
		q.pop();
		if (p.first - 1 >= 1 && map[p.first - 1][p.second] == '.' && flag[p.first - 1][p.second] == 0) {
			q.push(make_pair(p.first - 1, p.second));
			flag[p.first - 1][p.second] = 1;
		}
		
		if (p.second - 1 >= 1 && map[p.first][p.second - 1] == '.' && flag[p.first][p.second - 1] == 0) {
			q.push(make_pair(p.first, p.second - 1));
			flag[p.first][p.second - 1] = 1;
		}
		
		if (p.first + 1 <= n && map[p.first + 1][p.second] == '.' && flag[p.first + 1][p.second] == 0) {
			q.push(make_pair(p.first + 1, p.second));
			flag[p.first + 1][p.second] = 1;
		}
		
		if (p.second + 1 <= m && map[p.first][p.second + 1] == '.' && flag[p.first][p.second + 1] == 0) {
			q.push(make_pair(p.first, p.second + 1));
			flag[p.first][p.second + 1] = 1;
		}
	}
	return false;
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	if (bfs()) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	
	
	return 0;
}
