#include <bits/stdc++.h>
#define time first
#define power second
using namespace std;

const int N = 2e5 + 10;

typedef pair<int, int> node;

priority_queue <node, vector<node>, greater<node> > q[N];
int s[N]; 

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	while (m--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		while (!q[b].empty() && q[b].top().time <= a) {
			s[b] += q[b].top().power;
			q[b].pop();
		}
		if (d > s[b]) cout << -1 << endl;
		else {
			s[b] -= d;
			q[b].push({a + c, d});
			cout << s[b] << endl;
		}
	}
	return 0;
}

