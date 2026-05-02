#include <bits/stdc++.h>
using namespace std;

long long n, h[300005];
stack<long long> st;
long long ans;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && h[st.top()] < h[i]) {
            ans += i - st.top() + 1;
            st.pop();
        }
        if (!st.empty()) ans += i - st.top() + 1;
        st.push(i);
    }
    cout << ans;
    return 0;
}