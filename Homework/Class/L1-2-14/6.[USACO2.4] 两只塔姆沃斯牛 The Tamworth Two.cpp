#include <bits/stdc++.h>
using namespace std;

int fx, cx, fy, cy;
int fxn, cxn, fyn, cyn;
int fdir = 1, cdir = 1;
char mp[20][20];

void fmove() {
    if (fdir == 1) {
        fxn = fx - 1;
        fyn = fy;
    }
    if (fdir == 2) {
        fxn = fx;
          fyn = fy + 1;
    }
    if (fdir == 3) {
        fxn = fx + 1;
        fyn = fy;
    }
    if (fdir == 4) {
        fxn = fx;
        fyn = fy - 1;
    }
    
    if (fxn > 0 && fyn > 0 && fxn <= 10 && fyn <= 10 && mp[fxn][fyn] == '.') {
        fx = fxn;
        fy = fyn;
    }
    else {
        fdir++;
        if (fdir > 4) {
            fdir = 1;
        }
    }
}

void cmove() {
    if (cdir == 1) {
        cxn = cx - 1;
        cyn = cy;
    }
    if (cdir == 2) {
        cxn = cx;
        cyn = cy + 1;
    }
    if (cdir == 3) {
        cxn = cx + 1;
        cyn = cy;
    }
    if (cdir == 4) {
        cxn = cx;
        cyn = cy - 1;
    }
    
    if (cxn > 0 && cyn > 0 && cxn <= 10 && cyn <= 10 && mp[cxn][cyn] == '.') {
        cx = cxn;
        cy = cyn;
    }
    else {
        cdir++;
        if (cdir > 4) {
            cdir = 1;
        }
    }
}

int main(){
	for (int i = 1; i <= 10; i++) {
	    for (int j = 1; j <= 10; j++) {
	        cin >> mp[i][j];
	        if (mp[i][j] == 'F') {
	            fx = i;
	            fy = j;
	            mp[i][j] = '.';
	        }
	        if (mp[i][j] == 'C') {
	            cx = i;
	            cy = j;
	            mp[i][j] = '.';
	        }
	    }
	}
	int ans = 0;
	while (1) {
	    fmove();
	    cmove();
	    ans++;
	    if (ans > 10010) {
	        cout << 0;
	        return 0;
	    }
	    if (cx == fx && cy == fy) {
	        cout << ans;
	        return 0;
	    }
	}
	
	return 0;
}
