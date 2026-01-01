#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int head[1000005], to[1000005], nxt[1000005], w[1000005], n, m, idx; 

void addEdge(int u, int v, int k) {
	to[idx] = v;
	w[idx] = k;
	nxt[idx] = head[u];
	head[u] = idx++;
}

int main(){
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	for (int i = 1; i <= m; i++) {
		int u, v, k;
		cin >> u >> v >> k;
		addEdge(u, v, k);
	}
	for (int i = 0; i < n; i++) {
		cout << i << ":";
		for (int j = head[i]; j != -1; j = nxt[j]) {
			printf("[%d,%d]", to[j], w[j]);
		} 
		cout << endl;
	}
	return 0;
}
