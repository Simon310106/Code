#include <bits/stdc++.h>
using namespace std;

stack <int> s;
int a[1005], b[1005];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i - 1] = i;
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
    cout << (s.empty() ? "YES" : "NO");
    return 0;
}