#include <bits/stdc++.h>
using namespace std;

double stodn(string s){
	double re;
	bool flag = 1;
	int c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			if (flag) {
				re = re * 10 + s[i] - '0';
			}
			else {
				c++;
				re += pow(10, -c) * (s[i] - '0');
			}
		}
		else {
			flag = 0;
			c = 0;
		}
	}
	return re;
}

double Inverse_Polish_expression() {
	string oper;
	cin >> oper;
	if (oper == "+")
		return Inverse_Polish_expression() + Inverse_Polish_expression();
	else if (oper == "-")
		return Inverse_Polish_expression() - Inverse_Polish_expression();
	else if (oper == "*")
		return Inverse_Polish_expression() * Inverse_Polish_expression();
	else if (oper == "/")
		return Inverse_Polish_expression() / Inverse_Polish_expression();
	else
		return stodn(oper);
}

int main(){
	printf("%f\n", Inverse_Polish_expression());
	
	return 0;
}
