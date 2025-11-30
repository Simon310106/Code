#include <bits/stdc++.h>
using namespace std;

int st, ed;

int extend(queue<int> &q, int *pa, int *pb) {
    int d = pa[q.front()];
    while (q.size() && pa[q.front()] == d) {
        int x = q.front();
        q.pop();
        //+1
        for (int i = 0; i < 4; i++) {
            string s = to_string(x);
            if (s[i] == '9') {
                s[i] = '1';
            }
            else s[i]++;
            int y = stoi(s);
            if (pb[y] != -1) {
                return pb[y] + pa[x] + 1;
            } else if (pa[y] != -1) {
                continue;
            }
            pa[y] = pa[x] + 1;
            q.push(y);
        }
        //-1
        for (int i = 0; i < 4; i++) {
            string s = to_string(x);
            if (s[i] == '1') {
                s[i] = '9';
            }
            else s[i]--;
            int y = stoi(s);
            if (pb[y] != -1) {
                return pb[y] + pa[x] + 1;
            } else if (pa[y] != -1) {
                continue;
            }
            pa[y] = pa[x] + 1;
            q.push(y);
        }
        // swap
        for (int i = 0; i < 3; i++) { 
            string s = to_string(x);
            swap(s[i], s[i + 1]);
            int y = stoi(s);
            if (pb[y] != -1) {
                return pb[y] + pa[x] + 1;
            } else if (pa[y] != -1) {
                continue;
            }
            pa[y] = pa[x] + 1;
            q.push(y);
        }

    }
    return -1;
}

int bfs() {
    if (st == ed) return 0;
    int dis_a[10005], dis_b[10005];
    memset(dis_a, -1, sizeof(dis_a)); // 标记 & 距离
    memset(dis_b, -1, sizeof(dis_b));
    queue<int> qa, qb;
    qa.push(st), qb.push(ed); // qa 从起点 bfs， qb 从终点 bfs
    dis_a[st] = 0, dis_b[ed] = 0;
    while (qa.size() && qb.size()) {
        int ans = -1;
        if (qa.size() <= qb.size()) {
            ans = extend(qa, dis_a, dis_b); // 操作队列 a
        } else ans = extend(qb, dis_b, dis_a); // 操作队列 b
        if (ans > 0) return ans;
    }
}

int main(){
    int T;
    cin >> T;
    while (T--) {
        cin >> st >> ed;
        cout << bfs() << endl;
    }
    return 0;
}