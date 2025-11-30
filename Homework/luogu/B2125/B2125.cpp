#include <bits/stdc++.h>
using namespace std;

struct student {
    string name;
    int score;
}s[105];

bool cmp(student s1, student s2) {
    return s1.score > s2.score;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].score >> s[i].name;
    }
    sort(s, s + n, cmp);
    cout << s[0].name;

    return 0;
}