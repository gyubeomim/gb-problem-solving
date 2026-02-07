#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int digitLen(ll x){
    int d = 0;
    while(x){ d++; x /= 10; }
    return max(d, 1);
}

void solve(int k, int p, int d){

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("data/1171.txt", "r", stdin);
#endif
    ll N;
    scanf("%lld", &N);

    const int W = 11;
    ll pow10_[W];
    pow10_[0] = 1;

    for(int i = 1; i < W; i++) 
        pow10_[i] = pow10_[i-1] * 10;

    vector<ll> ans;
    ans.reserve(200);

    for(int p = 0; p < W-1; p++){
        ll pw = pow10_[p];

        for(int d = 0; d <= 9; d++){
            if(d * pw > N) break;

            ll l = (N - d*pw) / pw / 11;
            ll r2 = N - (11LL*l + d)*pw;

            if(d == 0 && l == 0) continue;

            if(r2 & 1LL) continue;      // should be even
            ll r = r2/2;
            if(r >= pw) continue;          

            ll x = (10LL*l + d)*pw + r;
            ll y = N - x;

            if(x < 10) continue;           
            int k = digitLen(x);
            if(digitLen(y) >= k) continue;  

            if(y >= pow10_[k-1]) continue;  // Y < 10^(k-1)

            ans.push_back(x);
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++){
        ll X = ans[i];
        ll Y = N - X;
        int w = digitLen(X) - 1;          
        printf("%lld + %0*lld = %lld\n", X, w, Y, N);
    }
}