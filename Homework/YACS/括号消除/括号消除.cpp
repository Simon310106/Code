#include <bits/stdc++.h>
using namespace std;

stack<char> st;

int main(){
    char c;
    while (cin >> c) {
        if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
        }
    }
    cout << st.size();
    return 0;
}