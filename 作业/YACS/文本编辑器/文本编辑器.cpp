#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string v;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'i') {
            char t;
            cin >> t;
            v.insert(v.begin() + cnt, t);
            cnt++;
        }
        else if (c == 'f') {
            if (cnt < v.size()) {
                cnt++;
            }
        }
        else if (c == 'b') {
            if (cnt > 0) {
                cnt--;
            }
        }
        else if (c == 'd') {
            if (cnt < v.size()) {
                v.erase(v.begin() + cnt);
            }
        }
    }
    cout << v;
    return 0;
}