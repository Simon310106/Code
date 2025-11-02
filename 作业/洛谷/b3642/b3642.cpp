#include <bits/stdc++.h>
using namespace std;

int n;

struct node {
    int right, left;
}a[1000005];

void front(int x) {
    if (x > 0) {
        cout << x << " ";
        front(a[x].left);
        front(a[x].right);
    }
}

void back(int x) {
    if (x > 0) {
        back(a[x].left);
        back(a[x].right);
        cout << x << " ";
    }
}

void in(int x) {
    if (x > 0) {
        in(a[x].left);
        cout << x << " ";
        in(a[x].right);
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].left >> a[i].right;
    }
    front(1);
    cout << endl;
    in(1);
    cout << endl;
    back(1);
    cout << endl;

    return 0;
}