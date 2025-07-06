#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <string> v(n + 5);
    int cnt = -1;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'v') {
            string s;
            cin >> s;
            v.resize(cnt + 1);
            v.push_back(s);
            cout << s << endl;
            cnt++;
        }
        else if (c == 'b') {
            if (cnt > 0) {
                cout << v[--cnt] << endl;
            }
            else {
                cout << "?" << endl;
            }
        }
        else if (c == 'f') {
            if (cnt < v.size() - 1) {
                cnt++;
                cout << v[cnt] << endl;
            }
            else {
                cout << "?" << endl;
            }
        }
    }
    
    return 0;
}
