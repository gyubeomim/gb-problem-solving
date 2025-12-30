#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using LL = long long;

LL d[100001];
LL A[100001];

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  d[0] = 1;
  d[1] = 0;
  d[2] = 3;

  for(int i=3; i<=n; i++) {
    d[i] = d[i] + d[i-2]*3;
    for(int j=4; j<=i; j+=2) {
      d[i] = d[i] + d[i-j]*2;
    }
  }

  cout << d[n] << '\n';

  return 0;
}
