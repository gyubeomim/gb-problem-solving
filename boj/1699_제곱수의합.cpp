#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[100001];
int A[100001];

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  for(int i=1; i<=n; i++) d[i] = 9999;

  for(int i=1; i*i<=n; i++) {
    for(int j=i*i; j<=n; j++) {
        d[j] = std::min(d[j - i * i] + 1, d[j]);
    }
  }

  cout << d[n] << '\n';

  return 0;
}