#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9;

int d[201][201];

int f(int n, int k) {
  if(k==1) return 1;
  int &ret = d[n][k];
  if(ret != 0) return ret;
  ret = 0;

  for(int i=0; i<=n; i++) {
    ret = (ret + f(n-i, k-1)) % MOD;
  }
  return ret;
}

int main(int argc, char const *argv[]) {
  int n,k;
  cin >> n >> k;

  // memset(d, -1, sizeof(d));

  printf("%d\n", f(n,k));

  return 0;
}