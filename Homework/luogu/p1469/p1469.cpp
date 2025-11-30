#include <iostream>
using namespace std;

int main(){
	int n, ans = 0, a;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		ans ^= a;
	}
	printf("%d", ans);
	
	return 0;
}
