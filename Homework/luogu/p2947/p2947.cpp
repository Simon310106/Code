#include <bits/stdc++.h>
using namespace std;

int n;
int h[1000005], R[1000005];
stack<int> st;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && h[st.top()] < h[i]) {
            R[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << R[i] << endl;
    }
    return 0;
}