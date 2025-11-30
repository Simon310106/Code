#include <bits/stdc++.h>
#include <algorithm>
#define int long long
using namespace std;

int a, b, c; 

signed main(){
    int d = a * b / __gcd(a, b);
    cout <<  c * d / __gcd(c, d);
    return 0;
}
