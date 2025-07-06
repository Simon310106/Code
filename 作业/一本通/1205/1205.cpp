#include <bits/stdc++.h>
using namespace std;

void hanoisteps(int n, char a, char c, char b) {
	if (n == 0) {
		return;
	}
	hanoisteps(n - 1, a, b, c);
	printf("%c->%d->%c\n", a, n, b);
	hanoisteps(n - 1, c, a, b);
}

int main(){
	int n;
	char a, b, c;
	cin >> n >> a >> b >> c;
	hanoisteps(n, a, c, b);
	return 0;
}
