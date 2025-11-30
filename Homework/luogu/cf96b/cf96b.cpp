#include <bits/stdc++.h>
#include <queue>
using namespace std;

long long n;
pair<long long, int> temp;

long long bfs() {
	queue<pair<long long, int> > q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp.first >= n && temp.second == 0) {
			return temp.first;
		}
		q.push(make_pair(temp.first * 10 + 4, temp.second + 1));
		q.push(make_pair(temp.first * 10 + 7, temp.second - 1));
	}
}

int main(){
	cin >> n;
	cout << bfs();
	
	return 0;
}
