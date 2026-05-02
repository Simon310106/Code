#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], u[N];

int main(){
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> u[i];
    }
    int get = 0;
    priority_queue<int> qma;
    priority_queue<int, vector<int>, greater<int>> qmi;
    for (int i = 1; i <= n; i++) {
        if (!qma.empty() && qma.top() <= a[i]) {
            qma.push(a[i]);
        }
        else {
            qmi.push(a[i]);
        }
        while {
            
        }
    }
    return 0;
}