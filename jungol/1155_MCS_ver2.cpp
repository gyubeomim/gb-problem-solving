#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using ull = unsigned long long;
using namespace std;

const int LM = 60005;
int k;
string S;
unordered_map<ull, int> hmap;

ull getKey(int c[]){
	ull key=0;
	for(int i=0;i<4;i++){
		key = key*(k+1) + c[i];
	}
	return key;
}

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/MCS2.txt", "r", stdin);
	#endif

    hmap.clear();
    cin >> k >> S;
    int cnt[4] = {};
  
    // sliding window
    for(int i=0;i<S.length();i++){
        if(S[i] == 'A') cnt[0]++;
        if(S[i] == 'C') cnt[1]++;
        if(S[i] == 'G') cnt[2]++;
        if(S[i] == 'T') cnt[3]++;

        if(i>=k){
            if(S[i-k]=='A') cnt[0]--;
            if(S[i-k]=='C') cnt[1]--;
            if(S[i-k]=='G') cnt[2]--;
            if(S[i-k]=='T') cnt[3]--;
        }

        if(i>=k-1){
            ull key = getKey(cnt);
            hmap[key]++;
        }
    }
    int ans =0;
    for(auto p : hmap){
        ans = max(ans, p.Y);
    }
    printf("%d\n",ans);

}