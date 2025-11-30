#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int n, m;
vector<LL> wp[1005];
LL check(int tar)
{
    LL sum = 0, now = wp[1].size();
    vector<LL> rem;
    for (int i = 2; i <= n; i++)
        if (!wp[i].empty())
        {
            int numi = max((int)wp[i].size() - tar + 1, 0); 
            now += numi;                                    
            for (int j = 0; j <= numi - 1; j++)
                sum += wp[i][j];
            for (int j = numi; j <= (int)wp[i].size() - 1; j++)
                rem.push_back(wp[i][j]);
        }
    if (now < tar)
    {
        sort(rem.begin(), rem.end());
        for (LL ele : rem)
        {
            sum += ele;
            now++;
            if (now == tar)
                break;
        }
    }
    return sum;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int p, c;
        cin >> p >> c;
        wp[p].push_back(c);
    }
    for (int i = 1; i <= n; i++)
        if (!wp[i].empty())
            sort(wp[i].begin(), wp[i].end());
    LL ans = 1e18;
    for (int i = max((int)wp[1].size(), 1); i <= m; i++)
        ans = min(ans, check(i));
    cout << ans;
    return 0;
}