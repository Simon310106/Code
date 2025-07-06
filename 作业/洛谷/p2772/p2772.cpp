#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;

struct node {
	int x, y;
}lst[N];

int n;

bool cmp(node a, node b) {
	if (a.y == b.y) {
		return a.x > b.x;
	}
	return a.y > b.y;
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> lst[i].x >> lst[i].y;
	}
	sort(lst + 1, lst + 1 + n, cmp);
	int ma = -1;
	for (int i = 1; i <= n; i++) {
		if (lst[i].x > ma) {
			ma = lst[i].x;
			if (i != 1) {
				cout << ",";
			}
			cout << "(" << lst[i].x << "," << lst[i].y << ")";
		}
	}
	
	return 0;
}

