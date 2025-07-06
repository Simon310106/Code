#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	for (int a = 0; a <= sqrt(n); a++) {
		for (int b = a; b <= sqrt(n); b++) {
			for (int c = b; c <= sqrt(n); c++) {
				int d = n - a * a - b * b - c * c;
				if (int(sqrt(d)) * int(sqrt(d)) == d) {
					if (c <= int(sqrt(d)))
						printf("%d %d %d %d\n", a, b, c, int(sqrt(d)));
				}
			}
		}
	} 
	return 0;
}

