#include <cstdio>
#include <iostream>

using namespace std;

using LL = long long;

LL d[100][10];


int main(int argc, char const *argv[]) {
  int n;
  cin >> n;

  for(int i=1; i<=9; i++) {
    d[1][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 9; j++) {
      if (j == 9)
        d[i][j] = d[i - 1][j - 1];
      else if (j == 0)
        d[i][j] = d[i - 1][j + 1];
      else
        d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
      d[i][j] %= 1000000000;
    }
  }

  LL result = 0;
  for (int i = 0; i <= 9; i++) {
    result += d[n][i];
  }

  cout << result % 1000000000 << '\n';

  return 0;
}
