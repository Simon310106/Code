#include <bits/stdc++.h>
using namespace std;

int main(){
    double x1, x2, x3, y1, y2, y3;
    double sum = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    sum += sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    sum += sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    sum += sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    cout << fixed << setprecision(2) << sum;
    return 0;
}