#include <bits/stdc++.h>
using namespace std;

float dis(float x1, float y1, float x2, float y2) {
	return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
}

float s(float a, float b, float c) {
	float p = (a + b + c) / 2.0;
	return pow(p * (p - a) * (p - b) * (p - c), 0.5);
}

int main(){
	float x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	float a, b, c;
	a = dis(x1, y1, x2, y2);
	b = dis(x2, y2, x3, y3);
	c = dis(x1, y1, x3, y3);
	cout << fixed << setprecision(2) << s(a, b, c);
	return 0;
}
