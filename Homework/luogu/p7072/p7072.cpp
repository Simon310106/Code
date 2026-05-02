#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main(){
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    priority_queue<int> qma;
    priority_queue<int, vector<int>, greater<int>> qmi;
    for (int i = 1; i <= n; i++) {
        if (!qmi.empty() && qmi.top() <= a[i]) {
            qmi.push(a[i]);
        }
        else {
            qma.push(a[i]);
        }
        int k = max(1, i * w / 100);
        while (qmi.size() > k) {
            qma.push(qmi.top());
            qmi.pop();
        }
        while (qmi.size() < k && !qma.empty()) {
            qmi.push(qma.top());
            qma.pop();
        }
        cout << qmi.top() << " ";
    }
    return 0;
}