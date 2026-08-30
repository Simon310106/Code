#include <bits/stdc++.h>
using namespace std;

int math(int a, char b, int c){
	switch(b) {
		case '+':
			return a + c;
		case '-':
			return a - c;
		case '*':
			return a * c;
		case '/':
			return a / c;
		case '%':
			return a % c;
	}
}

int main(){
	int a, b;
	char c;
	cin >> a >> c >> b;
	cout << math(a, c, b);
	return 0;
}
