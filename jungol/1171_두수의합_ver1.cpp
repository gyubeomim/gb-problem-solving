#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int digitLen(ll x){
    int d = 0;
    while(x){ d++; x/=10; }
    return max(d, 1);
}

ll N, pow10_[20];

struct Data { 
    ll x, y; 
    int w; 
};
vector<Data> ans;

void solve(int k, int p, int digit){
    if(p == k-1 && digit == 0) return; 

    ll pw = pow10_[p];                 
    ll M = N - digit * pw;
    if(M < 0) return;

    ll r = (p == 0 ? 0LL : (M % pw));  // M mod 10^p
    if(p >= 1 && (r & 1LL)) return;    // 2*l = r (mod 10^p) -> no solution if r odd

    ll rcand[2]; 
    int cnt = 0;

    if(p == 0){
        rcand[cnt++] = 0;
    }else{
        ll mod = pw / 2;               // 5*10^(p-1)
        ll base = (r / 2) % mod;       // l ≡ r/2 (mod 10^p/2)
        rcand[cnt++] = base;
        if(base + mod < pw) rcand[cnt++] = base + mod;
    }

    ll den = 11 * pw;
    for(int t = 0; t < cnt; t++){
        ll r = rcand[t];
        ll rem = M - 2 * r;

        if(rem < 0) continue;
        if(rem % den) continue;

        ll l = rem / den;
        ll x = l * pw * 10 + digit * pw + r;
        ll y = l * pw + r;

        if(x < 10) return;          
        if(x + y != N) return;      
        if(digitLen(x) != k) return; 
        ans.push_back({x, y, k-1}); 
    }
}

bool CmpLess(const Data& a, const Data& b){
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.w < b.w;
}

bool CmpEq(const Data& a, const Data& b){
    return a.x == b.x && a.y == b.y && a.w == b.w;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("data/1171.txt", "r", stdin);
#endif
    scanf("%lld", &N);

    int maxK = digitLen(N);

    pow10_[0] = 1;
    for(int i = 1; i < maxK; i++) 
        pow10_[i] = pow10_[i-1] * 10;

    ans.reserve(5000);

    for(int k = 2; k <= maxK; k++)
        for(int p = 0; p < k; p++)
            for(int d = 0; d <= 9; d++)
                solve(k, p, d);

    sort(ans.begin(), ans.end(), CmpLess);
    ans.erase(unique(ans.begin(), ans.end(), CmpEq), ans.end());

    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%lld + %0*lld = %lld\n", ans[i].x, ans[i].w, ans[i].y, N);
}