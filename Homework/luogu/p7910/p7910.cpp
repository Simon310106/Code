#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[8005];

int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (q--) {
		int opt, x, v;
		cin >> opt;
		if (opt == 1) {
			cin >> x >> v;
			a[x] = v;
		}
		else {
			int b[8005];
			cin >> x;
			memcpy(b, a, sizeof a);
			int idx = x;
			for (int i = 1; i <= n; i++)
				for (int j = i; j >= 2; j--)
					if (b[j] < b[j-1]) {
						if (j == idx) idx = j - 1;
						if (j - 1 == idx) idx = j;
						int t = b[j-1];
						b[j-1] = b[j];
						b[j] = t;
					}
			
			cout << idx << endl;
		}
	}
	return 0;
}

