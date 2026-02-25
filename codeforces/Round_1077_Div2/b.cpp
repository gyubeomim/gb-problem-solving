#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
  freopen("data/1077b.txt", "r", stdin);
#endif
  int T; scanf("%d", &T);
  while(T--) {
    int n; scanf("%d", &n);
    string s; cin >> s;

    int ans = 0;
    for(char c: s) 
					if(c=='1') ans++;

    for(int i = 0; i < n; ){
      if(s[i] == '1'){ i++; continue; }

      int j = i;
      while(j < n && s[j] == '0') j++;
      int L = j - i;

      bool left = (i-1 >= 0 && s[i-1] == '1');
      bool right = (j < n && s[j] == '1');
      if(left && right) ans += L / 3;
      else if(left || right) ans += (L + 1) / 3;
      else ans += (L + 2) / 3;
      i = j;
    }
    printf("%d\n", ans);
  }
}