#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

string s;

int main(){
    int n, m;
    cin >> n;
    while (n--) {
        cin >> s;
        mp[s] = 1;
    }
    cin >> m;
    while (m--) {
        cin >> s;
        if (mp[s] == 1) {
            cout << "OK" << endl;
            mp[s] = 2;
        }
        else if (mp[s] == 2) {
            cout << "REPEAT" << endl;
        }
        else {
            cout << "WRONG" << endl;
        }
    }
    return 0;
}