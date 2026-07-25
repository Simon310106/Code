#include <bits/stdc++.h>
using namespace std;

struct node {
    int a, b;
}cow[20];
int n, p[20];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cow[i].a;
    }
    for (int i = 1; i <= n; i++) {
        cin >> cow[i].b;
    }
    for (int i = 1; i <= n; i++) {
    	p[i] = i;
	}
	int ans = INT_MAX;
    do {
    	int s = n;
    	for (int i = 1; i < n; i++) {
    		s += max(cow[p[i]].b, cow[p[i + 1]].a);
		}
		ans = min(ans, s);
	} while (next_permutation(p + 1, p + 1 + n));
	cout << ans;
    return 0;
}
