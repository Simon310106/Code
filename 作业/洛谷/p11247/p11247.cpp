#include <bits/stdc++.h>
using namespace std;

int m, n, k, f[100005], d[100005], sum, ans;

struct node{
	int s, w;
}a[100005];

bool cmp(node i, node j) {
	return i.w > j.w; 
}

int main(){
	cin >> m >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].w;
	}
	sort 
	return 0;
}

