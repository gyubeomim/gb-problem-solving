#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m,A[2000001];

int main() {
  cin >> n >> m;

  n+=m;

  for(int i=0;i<n;i++){
    cin>>A[i];
  }

  std::sort(A,A+n);

  for(int i=0;i<n;i++){
    cout << A[i] << " ";
  }

  return 0;
}
