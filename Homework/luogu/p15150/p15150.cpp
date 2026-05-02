#include <bits/stdc++.h>
using namespace std;

long long n, h[200005], ma, ans;
long long R[200005], L[200005];
stack<long long> st;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        ma = max(h[i], ma);
    }
    memset(L, -1, sizeof L);
    memset(R, -1, sizeof R);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] < h[i]) {
            R[st.top()] = i;
            st.pop();
        }
        if (!st.empty()) L[i] = st.top();
        st.push(i);
    }
    for (int i = 0; i <= n; i++) {
        if (L[i] == -1 && R[i] == -1) continue;
        else if (L[i] == -1) ans += abs(i - R[i]);
        else if (R[i] == -1) ans += abs(i - L[i]);
        else ans += min(abs(i - L[i]), abs(i - R[i]));
    }
    cout << ans;
    return 0;
}