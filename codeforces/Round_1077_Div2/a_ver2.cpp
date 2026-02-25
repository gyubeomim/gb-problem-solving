#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 200005;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
  freopen("data/1077a.txt", "r", stdin);
#endif
  int T; scanf("%d", &T);
  while(T--) {
    int n; scanf("%d", &n);

    int p[LM], used[LM];
    memset(used, 0, sizeof(used));

    p[n] = n;
    used[n] = 1;

    int cur = n;
    for(int i=n-1; i>=1; i--){
      int a = cur-i;
      int b = cur+i;
      int next = -1;

      if(a>=1 && a<=n && !used[a]) next = a;
      else next = b;

      p[i] = next;
      used[next] = 1;
      cur = next;
    }

    for(int i=1; i<=n; i++){
      printf("%d ", p[i]);
    }puts("");

  }
}