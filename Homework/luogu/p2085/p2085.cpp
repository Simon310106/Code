#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int A[N], B[N], C[N], ans[N];
priority_queue<int> q;

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }
    for (int i = 1; i <= n; i++) {
        int a = A[i], b = B[i], c = C[i];
        for (int j = 1; j <= m; j++) {
            int f = a * j * j + b * j + c;
            if (i == 1) q.push(f);
            else {
                if (f < q.top()) {
                    q.push(f);
                    q.pop();
                }
                else {
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        ans[i] = q.top();
        q.pop();
    }
    for (int i = m; i >= 1; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}