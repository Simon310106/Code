#include <bits/stdc++.h>
using namespace std;

string s[100];

struct node{
    int cnt, num;
    string color;
}a[256];

int change(char s) {
    if (s <= '9') {
        return s - '0';
    }
    return s - 'A' + 10;
}

int cmp(node s1, node s2) {
    if (s1.cnt != s2.cnt)   return s1.cnt > s2.cnt;
    else    return s1.num < s2.num;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int len = s[0].length();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len; j += 2) {
            string t = s[i].substr(j, 2);
            int num = change(t[0]) * 16 + change(t[1]) * 1;
            if (a[num].cnt == 0) {
                a[num] = {1, num, t};
            }
            else {
                a[num].cnt++;
            }
        }
    }
    sort(a, a + 256, cmp);
    for (int i = 0; i < 16; i++) {
        cout << a[i].color;
    }
    cout << endl;

    for (int i = 0; i < n; i++, puts("")) {
        for (int j = 0; j < len; j += 2){
            int num = change(s[i][j]) * 16 + change(s[i][j + 1]) * 1;
            int mi = INT_MAX, id;
            for (int k = 0; k < 16; k++) {
                if (abs(a[k].num - num) < mi) {
                    mi = abs(a[k].num - num);
                    id = k;
                }
            }
            if (id < 10) cout << id;
            else cout << char('A' + (id - 10));
        }
    }

    return 0;
}