#include <iostream>
#include <queue>
using namespace std;

bool flag[1000001];
queue<pair<int, int> > q;
pair<int, int> temp;
int n;

void bfs(int a) {
	q.push(make_pair(1, 0));
	flag[1] = true;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp.first == a) {
			cout << temp.second;
			return;
		}
		if (temp.first - 1 >= 1 && !flag[temp.first - 1]) {
			flag[temp.first - 1] = true;
			q.push(make_pair(temp.first - 1, temp.second + 1));
		}
		if (temp.first + 1 <= n && !flag[temp.first + 1]) {
			flag[temp.first + 1] = true;
			q.push(make_pair(temp.first + 1, temp.second + 1));
		}
		if (temp.first * 2 <= n && !flag[temp.first * 2]) {
			flag[temp.first * 2] = true;
			q.push(make_pair(temp.first * 2, temp.second + 1));
		}
	}
	return;
}

int main(){
	cin >> n;
	bfs(n);
	
	return 0;
}
