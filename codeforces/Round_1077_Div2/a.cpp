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
  freopen("data/1077a.txt", "r", stdin);
#endif
  int T; scanf("%d", &T);
  while(T--) {
    int n; scanf("%d", &n);

    if(n==2){
      printf("1 2");
    }
    else if(n%2 == 1){
      int mid = n/2;
      printf("%d ", mid+1);
      for(int k = 1; k <= mid; k++){
        printf("%d %d ", mid+k+1, mid-k+1);
      }
    }else{
      int m = n-1;
      int mid = m/2;
      printf("%d ", mid+1);
      for(int k = 1; k <= mid; k++){
        printf("%d %d ", mid+k+1, mid-k+1);
      }
      printf("%d", n);
    }
    puts("");
  }
}