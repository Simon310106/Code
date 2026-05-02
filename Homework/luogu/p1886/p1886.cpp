#include <bits/stdc++.h>
using namespace std;
using PI = pair<int, int>;

const int N = 1e6 + 5;
int a[N], q1[N], q2[N];
int h1, t1, h2, t2;
int ans1[N], ans2[N];

int main(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        // 维护单调性
        while (h1 < t1 && a[q1[t1 - 1]] >= a[i]) {
            t1--;
        }
        // 加入新元素
        q1[t1++] = i;
        // 处理过期元素
        while (h1 < t1 && q1[h1] <= i - k) {
            h1++;
        }
        if (i >= k) ans1[i - k] = a[q1[h1]];

        // 维护单调性
        while (h2 < t2 && a[q2[t2 - 1]] <= a[i]) {
            t2--;
        }
        // 加入新元素
        q2[t2++] = i;
        // 处理过期元素
        while (h2 < t2 && q2[h2] <= i - k) {
            h2++;
        }
        if (i >= k) ans2[i - k] = a[q2[h2]];
    }
    for (int i = 0; i <= n - k; i++) {
        cout << ans1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= n - k; i++) {
        cout << ans2[i] << " ";
    }
    return 0;
}