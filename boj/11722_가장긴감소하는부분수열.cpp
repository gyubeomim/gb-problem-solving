#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[10001];
int A[10001];

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  for(int i=1; i<=n; i++){
      scanf("%d", &A[i]);
  }

  for(int i=1; i<=n; i++) {
    d[i] = 1;
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<i; j++) {
      if(A[i] < A[j]) {
        d[i] = std::max({d[i], d[j]+1});
      }
    }
  }

  cout << *std::max_element(d, d+n+1) << '\n';

  return 0;
}