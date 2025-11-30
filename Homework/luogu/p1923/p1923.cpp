#include <bits/stdc++.h>
using namespace std;

int a[5000005];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    // sort(a, a + n);
    nth_element(a, a + k, a + n);
    cout << a[k];
    return 0;
}