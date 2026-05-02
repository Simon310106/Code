#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+5;
ll a[N],st[N],top;
ll L[N],R[N];
struct Frac{
    long long n, d;
    const bool operator < (const Frac &other) const {
        return other.d*n < d*other.n;
    }
};
Frac calc(int i,int j,int k){
    // len = base + n/d;
    ll base = abs(i-k);
    ll n = a[i] - a[k];
    ll d = a[j] - a[k];
    ll g = gcd(base*d+n,d);
    return {(base*d+n)/g,d/g}; 
}
int main(){
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        while(top && a[st[top]] < a[i]){
            R[st[top]] = i;
            top--;
        }
        if(top) L[i] = st[top];
        st[++top] = i;
    }
    Frac ans = {0,1};
    for(int i = 1;i <= n;i++){
        if(L[i]){
            Frac t = calc(i,L[i],L[i]+1);
            ans = max(ans,t);
        }
        if(R[i]){
            Frac t = calc(i,R[i],R[i]-1);
            ans = max(ans,t);
        }
    }
    if(ans.n == 0) cout << 0 << endl;
    else if(ans.d == 1) cout << ans.n << endl;
    else cout << ans.n << '/' << ans.d << endl;
    return 0;
}