#include <iostream>
using namespace std;

char s[10050];

void capital(char s[]) {
	for (int i = 0; *(s + i) != '\0'; i++) {
		if (*(s + i) >= 'a' && *(s + i) <= 'z') {
			*(s + i) -= 32;
		}
	}
}

int main(){
	cin >> s;
	capital(s);
	cout << s;
	return 0;
}
