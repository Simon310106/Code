#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

struct Node1
{
    int p, c;
} e[N];

struct Node2
{
    int a, b;
} f[N], g[N];

int cntf, cntg;

bool cmp1(Node1 x, Node1 y)
{
    return x.p < y.p;
}

bool cmp2(Node2 x, Node2 y)
{
    return x.a - x.b > y.a - y.b;
}

bool cmp3(Node2 x, Node2 y)
{
    return x.b - x.a > y.b - y.a;
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        cin >> e[i].p >> e[i].c;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x >= y)
            f[++cntf] = {x, y};
        else
            g[++cntg] = {x, y};
    }
    sort(e + 1, e + n + 1, cmp1);
    sort(f + 1, f + cntf + 1, cmp2);
    sort(g + 1, g + cntg + 1, cmp3);
    int now = 1;
    long long ans = 0;
    for (int i = 1; i <= cntf; i++)
    {
        if (e[now].c == 0)
            now++;
        ans += 2ll * f[i].a * e[now].p + 2ll * f[i].b * (s - e[now].p);
        e[now].c--;
    }
    now = n;
    for (int i = 1; i <= cntg; i++)
    {
        if (e[now].c == 0)
            now--;
        ans += 2ll * g[i].a * e[now].p + 2ll * g[i].b * (s - e[now].p);
        e[now].c--;
    }
    cout << ans << endl;
    return 0;
}
