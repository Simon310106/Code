#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1050;

struct node {
	double weight;
	int id, fa, lc, rc;
	friend bool operator < (const node &a, const node &b) {
		return a.weight > b.weight;
	}
}ht[MAXN];

double w[MAXN];
priority_queue<node> hq;

bool Huffuman(int n) {
	if (n <= 1) {
		return 0;
	}
	int m = 2 * n - 1;
	for (int i = 1; i <= n; i++) {
		ht[i].weight = w[i];
		ht[i].id = i;
		ht[i].fa = 0;
		ht[i].lc = ht[i].rc = 0;
		hq.push(ht[i]);
	}
	node s1, s2;
	for (int i = n + 1; i <= m; i++) {
		s1 = hq.top(); hq.pop();
		s2 = hq.top(); hq.pop();
		ht[i].weight = s1.weight + s2.weight;
		ht[i].id = i;
		ht[i].fa = 0;
		ht[i].lc = s1.id;
		ht[i].rc = s2.id;
		ht[s1.id].fa = i;
		ht[s2.id].fa = i;
		hq.push(ht[i]);
	}
	return true;
}

void print() {
	node s = hq.top();
	queue<int> q;
	q.push(s.id);
	while (!q.empty()) {
		int idx = q.front();
		cout << ht[idx].weight << " ";
		q.pop();
		if (ht[idx].lc) {
			q.push(ht[idx].lc);
		}
		if (ht[idx].rc) {
			q.push(ht[idx].rc);
		}
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	if (Huffuman(n)) {
		print();
	}
	else {
		cout << "Error" << endl;
	}
	return 0;
}