#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int d[100001];
int A[100001];

int main() {
  int n;
  cin >> n;

  for(int i=1; i<=n; i++) {
    cin >> A[i];
  }

  d[0] = 0;
  d[1] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      d[i] = std::max(d[i], d[i - j] + A[j]);
    }
  }

  cout << d[n] << '\n';

  return 0;
}