#include <bits/stdc++.h>
using namespace std;

map <string, int> m;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int p;
        cin >> s >> p;
        m.insert(make_pair(s, p));
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        int x = m[s];
        cout << x << endl;
    }
    return 0;
}