#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    priority_queue<int> qma;
    priority_queue<int, vector<int>, greater<int>> qmi;
    for (int i = 1; i <= n; i++) {
        if (qmi.empty() || qmi.top() <= a[i]) {
            qmi.push(a[i]);
        }
        else {
            qma.push(a[i]);
        }
        while (abs(int(qmi.size() - qma.size())) > 1) {
            if (qmi.size() > qma.size()) {
                qma.push(qmi.top());
                qmi.pop();
            }
            else {
                qmi.push(qma.top());
                qma.pop();
            }
        }
        if (i % 2 != 0) {
            cout << (qma.size() > qmi.size() ? qma.top() : qmi.top()) << endl;
        }
    }
    return 0;
}