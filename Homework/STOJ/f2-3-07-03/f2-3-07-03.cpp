#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
int n;
int h[N], v[N];
int L[N], R[N], rec[N];
stack<int> st;

signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && h[st.top()] < h[i]) {
            // R[st.top()] = i;
            rec[i] += v[st.top()];
            st.pop();
        }
        if (!st.empty()) {
            // L[i] = st.top();
            rec[st.top()] += v[i];
        }
        st.push(i);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, rec[i]);
    }
    cout << ans;
    return 0;
}