#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q1;                             //大根堆
priority_queue<int, vector<int>, less<int>> q2;     //大根堆
priority_queue<int, vector<int>, greater<int>> q3;  //小根堆
struct node1 {
    int k;
    char c;
};
struct cmp {
    bool operator() (const node1 &a, const node1 &b) {
        if (a.k == b.k) {
            return a.c > b.c;   // k相等时, c小的优先
        } else {
            return a.k < b.k;   // k不等时, k大的优先
        }
    }
};
struct node2 {
    int k;
    char c;
    friend bool operator< (const node2 &a, const node2 &b) {
        if (a.k == b.k) {
            return a.c < b.c;   // k相等时, c大的优先
        } else {
            return a.k > b.k;   // k不等时, k小的优先
        }
    }
};
string s = "ABCDEF";
vector<int> v = {1, 1, 3, 4, 5, 5};
 
int main(){
    priority_queue<node1, vector<node1>, cmp> q4;
    for (int i = 0; i < 6; i++) {
        q4.push({v[i], s[i]});
    }
    cout << q4.top().k << " " << q4.top().c << endl;
    cout << endl;
    priority_queue<node2, vector<node2>> q5;
    for (int i = 0; i < 6; i++) {
        q5.push({v[i], s[i]});
    }
    cout << q5.top().k << " " << q5.top().c << endl;
    return 0;
}
