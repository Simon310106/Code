#include <bits/stdc++.h>
using namespace std;

int T, m;

int main(){
	cin >> T >> m;
	while (T--) {
		int a, b, c;
		int delta = b*b - 4*a*c;
		if (delta < 0) {
			cout << "NO" << endl;
			continue;
		}
		int q1_1 = -b, q1_2 = 2*a;
		int g1 = __gcd(abs(q1_1), abs(q1_2));
		q1_1 /= g1;
		q1_2 /= g1;
		if (q1_2 < 0) {
			q1_1 = -q1_1;
			q1_2 = -q1_2;
		}
//		if (q1_2 == 1 || q1_1 == 0) printf("%d", q1_1);
//		else printf("%d/%d+", q1_1, q1_2);
		int q2_1 = 1, q2_2 = 2*a, r = delta;
		for (int i = 2; i * i <= r; i++) {
			if (r % (i * i) == 0) {
				q2_1 *= i;
				r /= (i * i);
			}
		}
		int g2 = __gcd(abs(q2_1), abs(q2_2));
		q2_1 /= g2;
		q2_2 /= g2;
		if (q1_2 == 1 && q2_2 == 1 && r == 1) {
			printf("%d+", q2_1+q1_1);
			continue;
		}
		if (q1_2 == 1 && q1_1 != 0) {
			printf("%d+", q1_1);
		}
		else if (q1_1 != 0) {
			printf("%d/%d+", q1_1, q1_2);
		}
		if (r == 1) {
			if (q2_2 == 1) {
				printf("%d", q2_1);
			}
			else {
				printf("%d/%d", q2_1, q2_2);
			}
		}
		else {
			if (q2_1 == 1) {
				printf("sqrt(%d)/%d", r, q2_2);
			}
			else if (q2_2 == 1) {
				printf("%d*sqrt(%d)", q2_1, r);
			}
			else {
				printf("%d*sqrt(%d)/%d", q2_1, r, q2_2);
			}
		}
	}
	return 0;
}

