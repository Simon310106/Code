#include <bits/stdc++.h>
#include <string>
using namespace std;

string A, B;
string a[10], b[10];
int cnt = 1;

struct node {
    string cur;
    int cs;
}q[2000000];

int main(){
    cin >> A >> B;
    while (cin >> a[cnt] >> b[cnt]) cnt++;
    cnt -= 1;
    int l = 0, r = 1;
    q[r].cur = A;
    q[r].cs = 0;
    while (l < r) {
        l++;
        if (q[l].cs > 10) {
            cout << "NO ANSWER!" << endl;
            return 0;
        }
        for (int j = 1; j <= cnt; j++) {
            int pos = q[l].cur.find(a[j], 0);
            while(1) {
                if (pos == -1) {
                    break;
                }
                else {
                    r++;
                    q[r].cur = q[l].cur;
                    q[r].cs = q[l].cs + 1;
                    q[r].cur.replace(pos, a[j].length(), b[j]);
                    if (q[r].cur == B) {
                        cout << q[r].cs << endl;
                        return 0;
                    }
                    pos = q[l].cur.find(a[j], pos + 1);
                }
            }
        }
    }

    return 0;
}