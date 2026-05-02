#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 8e4 + 10;
ll n;
ll a[N], ans;
stack<int> st;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && st.top() <= a[i]) {
            st.pop();
        }
        if (!st.empty()) ans += st.size();
        st.push(a[i]);
    }
    cout << ans;
    return 0;
}