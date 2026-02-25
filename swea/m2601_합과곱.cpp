#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using i128 = __int128;
using namespace std;
 
const i128 INF = 0x3f3f3f3f3f3f3f3f;
 
ll findSqrt(i128 x){
    if(x<0) return -1;
    if(x==0) return 0;
     
    i128 lo=1, hi=min(x, INF);
    while(lo <= hi){
        i128 mid = (lo+hi) / 2;
        i128 sq = (i128)mid*mid;
        if(sq == x) return mid;
        if(sq < x) lo = mid+1;
        else hi = mid-1;
    }
    return -1;
}
 
int main(int argc, char **argv){
        int C; scanf("%d", &C);
        while(C--) {
            ll s, p; scanf("%lld%lld", &s, &p);
 
            i128 D = (i128)s*s - (i128)4*p;
 
            if(D<0) { printf("No\n"); continue; }
 
            ll sqD = findSqrt(D);
            if(sqD == -1) { printf("No\n"); continue; }
 
            if((s+sqD)%2 != 0 || (s-sqD)%2 != 0) { printf("No\n"); continue; }
 
            ll n = (s+sqD) / 2;
            ll m = (s-sqD) / 2;
 
            if(n>0 && m>0) printf("Yes\n"); 
            else printf("No\n");
        }
}