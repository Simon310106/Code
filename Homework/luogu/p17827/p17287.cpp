#include <bits/stdc++.h>
using namespace std;

int func(char c) {
    if (c <= 'C') return 1;
    else return 0;
}

int func2(char c) {
    if (c <= 'C') return c;
    else return c == 'D';
}

int main(){
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    f1 = (c1 == c2);
    f2 = (f1 && (s1.substr(0, 2) == s2.substr(0, 2)));
    f3 = (f2 && func(s1[2]) == func(s2[2]));
    f4 = (f3 && abs(func2(s1[2]) - func2(s2[2])) == 1);
    cout << f1 << f2 << f3 << f4;
    return 0;
}