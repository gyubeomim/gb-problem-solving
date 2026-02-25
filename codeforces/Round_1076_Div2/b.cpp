#include <bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("data/1076b.txt", "r", stdin);
#endif
    int T; scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        vector<int> p(n);
        for(int i=0;i<n;i++) scanf("%d", &p[i]);

        vector<int> sufmx(n), sufpos(n);
        int mx = -1, pos = -1;
        for(int i=n-1;i>=0;i--){
            if(p[i] > mx) mx = p[i], pos = i;
            sufmx[i] = mx;
            sufpos[i] = pos;
        }

        int l = -1;
        for(int i=0;i<n;i++){
            if(p[i] < sufmx[i]) { l = i; break; }
        }
        if(l != -1){
            int r = sufpos[l];
            reverse(p.begin() + l, p.begin() + r + 1);
        }

        for(int i=0;i<n;i++) 
					printf("%d ", p[i]);
				puts("");
    }
}