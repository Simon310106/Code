#include <bits/stdc++.h>
using namespace std;

int n;
string s;

char find (int x, int y) {
    if (x == y) {
        char tmp = (s[x] == '0' ? 'B' : 'I');
        cout << tmp;
        return tmp;
    }
    char a = find(x, (x + y) / 2);
    char b = find((x + y) / 2 + 1, y);
    char tmp = (a == b ? a : 'F');
    cout << tmp;
    return tmp;
}

int main(){
    cin >> n >> s;
    int len = pow(2, n);
    find (0, len - 1);
    return 0;
}