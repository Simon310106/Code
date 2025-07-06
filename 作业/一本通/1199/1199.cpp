#include <iostream>
#include <cstring>
using namespace std;

char s[15];
int len;

void myswap(char &a, char &b) {
	char t = a;
	a = b;
	b = t;
}

void arrange(int k) {
	if (k == len - 1) {
		cout << s << endl;
		return;
	}
	for (int i = k; i < len; i++) {
		myswap(s[k], s[i]);
		arrange(k + 1);
	}
	for (int i = k; i < len - 1; i++) {
		myswap(s[i], s[i + 1]);
	}

}

int main(){
	cin >> s;
	for (int i = 0; s[i] != '\0'; i++) {
		len++;
	}
	arrange(0);
	return 0;
}
