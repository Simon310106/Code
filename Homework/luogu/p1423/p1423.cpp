#include<bits/stdc++.h>
using namespace std;

int main() {
    double s, a = 2;
    int i;
    cin >> s;
    
    for (i = 0; s > 0; i++)
    {
    	s -= a;
    	a *= 0.98;
	}
	cout << i;
    return 0;
}
