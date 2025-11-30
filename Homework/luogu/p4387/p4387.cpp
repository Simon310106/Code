#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005];

int main(){
    int q;
    cin >> q;
    for (int x = 0; x < q; x++) {
        stack <int> s;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            s.push(a[i]);
            while (s.top() == b[j]) {
                s.pop();
                j++;
                if (s.empty()) {
                    break;
                }
            }
        }
        if (s.empty()) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}