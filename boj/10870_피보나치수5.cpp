#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fibo(int n) {
  if(n==0) { return 0; }
  else if(n==1) { return 1; }

  return fibo(n-2) + fibo(n-1);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int N;
  cin >> N;
  ll n = fibo(N);

  cout << n << endl;
  return 0;
}
