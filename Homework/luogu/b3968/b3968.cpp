#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

struct student {
    int chinese, math, english;
    int total;
    int id, pm;
    bool flag = 0;
} a[N];

bool cmp1(student a, student b) {
    if (a.total != b.total)
        return a.total > b.total;
    else if ((a.math + a.chinese) != (b.math + b.chinese))
        return (a.math + a.chinese) > (b.math + b.chinese);
    else if (max(a.math, a.chinese) != max(b.math, b.chinese))
        return max(a.math, a.chinese) > max(b.math, b.chinese);
    else {
        if (a.id < b.id)
            b.flag = 1;
        else
            a.flag = 1;
        return a.id < b.id;
    }
}

bool cmp2(student x, student y) {
    return x.id < y.id;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].chinese >> a[i].math >> a[i].english;
        a[i].total = a[i].chinese + a[i].math + a[i].english;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp1);
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i].total == a[i - 1].total 
        && a[i].chinese + a[i].math == a[i - 1].chinese + a[i - 1].math
        && max(a[i].chinese, a[i].math) == max(a[i - 1].chinese, a[i - 1].math)) {
            a[i].pm = cnt;
        }
        else {
            cnt = i;
            a[i].pm = cnt;
        }
    }
    sort(a + 1, a + 1 + n, cmp2);
    for (int i = 1; i <= n; i++) {
        cout << a[i].pm << endl;
    }
    return 0;
}