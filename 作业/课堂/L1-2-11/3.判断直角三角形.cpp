#include <bits/stdc++.h>
using namespace std;

string Righttriangle(int a, int b, int c) {
    if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
        return "True";
    }
    else {
        return "False";
    }
}

int main(){
    int n, a, b, c;
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cout << Righttriangle(a, b, c) << endl;
    }
//	system("pause");
	return 0;
}
