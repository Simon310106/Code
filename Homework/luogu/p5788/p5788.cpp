#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 5;
int R[N], st[N], a[N];
int L[N];
int top;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        while (top && a[st[top]] < a[i]) {
            // 栈顶元素小于x，说明栈顶元素右侧第一个比它大的元素就是i
            R[st[top]] = i;
            top--; // 出栈
        }
        if (st[top]) L[i] = st[top];
        st[++top] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << R[i] << " ";
    }
    return 0;
}