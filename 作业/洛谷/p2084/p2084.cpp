#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, cnt = 0, c;
    string n;
    cin >> m >> n;
    c = n.length() - 1;
    while (c >= 0) {
        cnt++;
        int t = n[cnt - 1] - 48;
        if (cnt == 1) {
            cout << t << "*" << m << "^" << c;
        }
        else if (t != 0) {
            cout << "+" << t << "*" << m << "^" << c;
        }
        c--;
    }
    
    return 0;
}