#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int N;
  cin >> N;
	
  int d[1001];
  d[0] = d[1] = 1;

  for(int i=2; i<=N; i++) {
	  d[i] = d[i-1] + 2*d[i-2];
	  d[i] %= 10007;
  }

  cout << d[N] << '\n';


  return 0;
}

