#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int d[10001];
int A[10001];

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  for(int i=0; i<n; i++) {
    d[i] = A[i];
    for(int j=0; j<i; j++) {
      if(A[j] < A[i] && d[i] < d[j] + A[i]) {
        d[i] = d[j] + A[i];
      }
    }
  }

  cout << *std::max_element(d, d+n+1) << '\n';

  return 0;
}