#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
  freopen("data/1076e.txt", "r", stdin);
#endif
  int T; 
  scanf("%d", &T);

  while(T--){
    int n; 
    scanf("%d", &n);

    vector<char> avail(n + 1, 0);

    for(int i = 0; i < n; i++){
      int x; scanf("%d", &x);
      if(x <= n) avail[x] = 1;
    }

    vector<vector<int>> divs(n + 1);
    for(int d = 2; d <= n; d++){
      if(!avail[d]) continue;
      for(int m = d; m <= n; m += d){
        divs[m].push_back(d);
      }
    }

    vector<int> dp(n + 1, INF);

    if(avail[1]) dp[1] = 1;

    for(int i = 2; i <= n; i++){
      if(avail[i]) dp[i] = 1; 

      for(int d : divs[i]){
        int prev = i / d;
        if(dp[prev] == INF) continue;
        dp[i] = min(dp[i], dp[prev] + 1);
      }
    }

    for(int i = 1; i <= n; i++){
      int ans = (dp[i] >= INF ? -1 : dp[i]);
      printf("%d ", ans);
    }puts("");
  }
}