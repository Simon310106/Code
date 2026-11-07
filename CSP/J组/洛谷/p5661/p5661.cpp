#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, ans;
int head = 1, tail = 1;

struct ticket {
	int price, time;
	bool used;
}q[N];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int opt, price, time;
		cin >> opt >> price >> time;
		if (opt == 0) {
			q[tail++] = {price, time, 0};
			ans += price;
		}
		while (time - q[head].time > 45) {
			head++;
		}
		if (opt == 1) {
			bool flag = 0;
			for (int i = head; i <= tail; i++) {
				if (q[i].price >= price && q[i].used == 0) {
					q[i].used = 1;
					flag = 1;
					break;
				}
			}
			if (!flag) {
				ans += price;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

